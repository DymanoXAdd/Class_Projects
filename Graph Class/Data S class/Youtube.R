
install.packages('devtools')
library(devtools)

devtools::install_github("soodoku/tuber")
library(tuber)

setwd("C:/Users/luisr/Desktop/Data S class")

client_id <- "943198196745-gvccrrkopeu0g40hm4huvpe8vpgsh97t.apps.googleusercontent.com"
client_secret <- "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"
yt_oauth(client_id,client_secret,token = '')

get_stats(video_id = "1Z6CHioIn3s")

get_video_details(video_id = "1Z6CHioIn3s")

search_result <- yt_search("League of Legends")
View(search_result)

comments <- get_comment_threads(c(video_id = "1Z6CHioIn3s"))
View(comments)

write.csv(comments, file = 'BurnItAllDownComments.csv')


install.packages('tm')
library(tm)
install.packages('SnowballC')
library(SnowballC)
install.packages('wordcloud')
library(wordcloud)

comments_corp = Corpus(VectorSource(comments$textOriginal))

comments_DTM = DocumentTermMatrix(comments_corp, control = list(removePunctuation=T, removeNumbers=T, stopwords=T))

as.matrix(comments_DTM[,1:5])

comments_terms=colSums(as.matrix(comments_DTM))
comments_terms_matrix = as.matrix(comments_terms)
comments_terms_matrix

wordcloud(words=names(comments_terms), freq = comments_terms, vfont=c('serif', 'bold italic'), color=1:nrow(comments_terms_matrix))
                                  
