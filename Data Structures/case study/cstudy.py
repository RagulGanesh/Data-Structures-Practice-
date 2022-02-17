from wordcloud import WordCloud,STOPWORDS #importing wordcloud and stopwords
import matplotlib.pyplot as plt
import re #importing regex module
file=open("Text.txt","r+")
d={}
exp=""
l=[]
file_content=file.read()
no_meaning= set(STOPWORDS) #It removes words such as whereas,often etc..
# print(no_meaning)
unwanted_characters=re.sub("[\W+\d+]+"," ",file_content) #deriving a string by removing punctuations,spaces etc...
# print(unwanted_characters.upper())
for i in unwanted_characters.upper():
    if(i!=" "):
        exp+=i
    else:
        l.append(exp)
        exp=""
# print(l) 
for i in l:#storing the keys with their frequencies as vzlues
    if i not in d.keys():
        d[i]=1
    else:
       d[i]=d.get(i,0)+1   
# print(d)  
required_info=sorted(d.items(), key=lambda x: x[1], reverse=True) #sorting the dictionary based on frequencies
# print(required_info) 
k=int(input("Enter top k words : "))
text=""
lis=[]
count=1
for i in required_info:
    if(count<=k):
        lis.append(i)
        count=count+1
    else:
        break
for i in lis:
    for j in range(i[1]):
        text=text+i[0]+" "
print(text)   
# print(text)
wordcloud = WordCloud(stopwords= no_meaning,background_color="black",width=480, height=480, max_words=50).generate(text)  #creating a wordcloud     
# print(required_info)
plt.figure()
plt.imshow(wordcloud)
plt.axis("off")
plt.margins(x=0, y=0)
plt.show()
wordcloud.to_file('word_cloud.png')
file.close()
       
