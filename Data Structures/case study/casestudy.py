from wordcloud import WordCloud
import matplotlib.pyplot as plt
file=open("Text.txt","r+")
d={}
exp=""
l=[]
for i in file.read():
    if(i in [" ",".","!","",".",";","\n","\'",",","-"]):
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
#print(sorted(d.items(), key=lambda x: x[1], reverse=True)) 
text=sorted(d.items(), key=lambda x: x[1], reverse=True)
print(text)
e=""
for i in text:
    e=e+" "+i[0]
wordcloud = WordCloud(width=480, height=480, max_words=50).generate(e)       
plt.figure()
plt.imshow(wordcloud, interpolation="bilinear")
plt.axis("off")
plt.margins(x=0, y=0)
plt.show()
file.close()