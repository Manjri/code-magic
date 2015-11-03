f = open('webserverAll_20150205.log', 'w+')
for num in range (1,3):
    f1 = open('webserver'+ str(num) +'_20150205.log')        
    f.write(f1.read())
f.close()    

f = open('webserverAll_20150205.log', 'r')
lines = [line for line in f]
f.close()

lines.sort()

f = open('webserverAll_20150205.log', 'w+')
f.writelines(lines)
f.close() 