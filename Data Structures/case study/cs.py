from wordcloud import WordCloud
import matplotlib.pyplot as plt
file=open("Text.txt","r+")
d={}
exp=""
l=[]
for i in file.read():
    if(i in [" ",".","!",""]):
        l.append(exp)
        exp=""
    else:
        exp+=i.lower() 
for i in l:
    if i not in d.keys():
        d[i]=1
    else:
       d[i]=d.get(i,0)+1   
#print(d)   
print(sorted(d.items(), key=lambda x: x[1], reverse=True))        
file.close()