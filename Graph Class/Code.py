#!/usr/bin/env python
# coding: utf-8

# In[40]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math
import scipy.stats as stats


# In[41]:


get_ipython().system('pip install pandas')


# In[95]:


movies = pd.read_csv("C:/Users/luisr/Downloads/airport_routes.csv")


# In[81]:


movies


# In[82]:


mov_min = movies['NumberOfRoutes'].min()
mov_min


# In[83]:


mov_max = movies['NumberOfRoutes'].max()
mov_max


# In[84]:


mov_mean = movies['NumberOfRoutes'].mean()
mov_mean


# In[85]:


mov_std = movies['NumberOfRoutes'].std()
mov_std


# In[86]:


mov_mount = len(movies)
mov_mount


# In[87]:


mov_lamda = 1/mov_mean
mov_lamda


# In[88]:


total = 0
for num in movies['NumberOfRoutes']:
    total += np.log(num / mov_min)
mov_alpha = 1 + (mov_mount/total)
mov_alpha


# In[89]:


movies.plot.hist(bins=100,color='red')


# In[90]:


plt.hist(movies['NumberOfRoutes'],bins=100,color='red')


# 

# In[91]:


def uniformdist(x,mn,mx):
    return 1/(mx-mn)

def powerlawdist(x,alpha,mn):
    return ((alpha-1)/mn) * ((x/mn)**(-alpha))


# In[92]:


mov_power_theory = []
x = []
for i in range(1,100):
    x += [i]
    mov_power_theory += [powerlawdist(i,mov_alpha,mov_min)]
plt.hist(mov_power_theory[0:50], bins=100)


# In[77]:


mov_normal_theory = np.random.normal(loc=mov_mean, scale = mov_std, size=1000)
plt.hist(mov_normal_theory, bins=100, color='lime')


# In[78]:


mov_expo_theory = np.random.exponential(scale=1/mov_lamda, size=1000)
plt.hist(mov_expo_theory, bins=100, color='blue')


# In[79]:


mov_uniform_theory=[]
x=[]
for i in range(round(mov_min), round(mov_max)):
    x+=[i]
    mov_uniform_theory += [uniformdist(i,mov_min,mov_max)]
plt.hist(mov_uniform_theory,bins=100,color='black')


# In[ ]:





# In[ ]:




