import numpy as np
import pandas as pd
import scipy.stats as stats
import matplotlib.pyplot as plt
import sklearn

from sklearn.datasets import load_boston
from sklearn.linear_model import LinearRegression
#from sklearn.cross_validation import train_test_split

#User defined values and creating data frame

trainingExamples=[(10.30,	183800),            #x1 is 10.30 and 183800 is y variable
                  (10.30,	183200),
                  (10.10,	174900),
                  (9.30,	173500),
                  (8.40,	172900),
                  (7.30,	173200),
                  (8.40,	173200),
                  (7.90,	169700),
                  (7.60,	174500),
                  (7.60,	177900),
                  (6.90,	188100),
                  (7.40,	203200),
                  (8.10,	230200),
                  (7.00,	258200),
                  (6.50,	309800),
                  (5.80,	329800)]
labels=['interestRate', 'Price']

bos = pd.DataFrame.from_records(trainingExamples, columns=labels)


print bos                  #prints the entire dataSet
print "X-Vector (mXn, 2X15).....5 rows printed only......\n"
print bos.head()            #prints the initial 5 rows
print "_________________________________\n"


lm=LinearRegression()
X=bos.drop('Price', axis=1)

lm.fit(X, bos.Price)                         #http://www.bigdataexaminer.com/2016/03/31/how-to-run-linear-regression-in-python-scikit-learn/

print "________________________________\n"
print "Vectors X and Y were passed to .fit() function intercept and parameters so obtained are"
print lm.intercept_
print lm.coef_

out=pd.DataFrame(zip(X.columns, lm.coef_),columns=['features','estimatedCoeffiecients'])


print out

plt.scatter(bos.interestRate, bos.Price)      #we are plotting on of feature(RM) wrt Y(price)
plt.xlabel("Interest Rate")
plt.ylabel("Housing Price")
plt.title("Relationship b/w Housing price and Interset rate")
plt.show()

