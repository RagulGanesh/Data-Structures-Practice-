from wordcloud import WordCloud,STOPWORDS
import wikipedia
import re

d = {}
meaning_less_words = set(STOPWORDS)       # like is,this,that,him,her,our,was,to,some,so,they....
info = wikipedia.summary("python")
print(meaning_less_words) 
info = re.sub('[^A-Za-z0-9]+', ' ', info) # removing special characters, symbols, punctation marks ...
info = info.upper()                       # converting into one case - UPPER
for word in info.split():
    d[word] = info.count(word)            # frequency of each words is maintained in dict-d
info = ""
sorted(d.items(),key = lambda x:x[1],reverse=True)
for word,COUNT in d.items():
    if len(info.split()) < 100:           # selecting 100 words
        info+=word+" "
print(info)
word_cloud = WordCloud(stopwords= meaning_less_words, width= 700,height=500).generate(info)
img = word_cloud.to_image()               # making into image
img.show()
