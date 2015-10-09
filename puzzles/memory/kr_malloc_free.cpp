#include <stdio.h>

typedef long Align; // for alignment to long boundary

union header
{
    struct
    {
        union header* ptr;
        unsigned size;
    }s;

    Align x;
};

typedef union header Header;

static Header base;             //empty list
static Header* freep = NULL;    //start of free list

void* kr_malloc(unsigned nbytes)
{

    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;

    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    if( (prevp = freep) == NULL )
    {
        // no free list yet

        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;

    }

    for( p = prevp->s.ptr; ;prevp = p, p=p->s.ptr)
    {
        if(p->s.size >= nunits) // big enough
        {
            if(p->s.size == nunits) // exactly
            {
                prevp->s.ptr = p->s.ptr;
            }
            else                // allocate the tail end
            {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }

            freep = prevp;
            return (void*)p+1;
        }

        if(p == freep)  //wrapped around free list
        {
            if((p=morecore(nunits)) == NULL)            //morecore asks the system for more memory and is machine dependent
                return NULL;        // none left
        }
    }

}

// Put block ap in free list

void kr_free(void* ap)
{
    Header *bp, *p;     // block pointer, free running pointer

    bp = (Header*)ap - 1;   // point to block header

    // bp should be placed in between p and p->next
    // look at http://www.cnblogs.com/sirkay777/archive/2009/03/04/1403374.html 

    for(p=freep; !(bp > p && bp < p->s.ptr); p=p->s.ptr)
        if( p>= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;      // freed block is at the start or end of the arena(linkedlist)

    // now place the pointerer and set the sizes correctly
    if(bp + bp->s.size == p->s.ptr)         // coalesce with upper neighbour
    {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    else
    {
        bp->s.ptr= p->s.ptr;
    }
    if(p + p->s.size == bp)                 // coalesce with lower neighbour
    {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else
    {
        p->s.ptr = bp;
    }
    freep = p;
}
