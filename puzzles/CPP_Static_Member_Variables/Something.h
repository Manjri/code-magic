class Something
{
private:
    static int s_nIDGenerator;
    int m_nID;
    static const double fudgeFactor;  
public:
    ~Something(){}
    Something() { m_nID = s_nIDGenerator++; }
    
    int GetID() const { return m_nID; }
};
