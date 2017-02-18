import numpy as np
import pandas as pd
import scipy.stats as stats
import matplotlib.pyplot as plt
import sklearn

from sklearn.datasets import load_boston
from sklearn.linear_model import LinearRegression
from sklearn.cross_validation import train_test_split

boston=load_boston()        #13 cols X 506 rows
print boston.feature_names

print boston.data

bos=pd.DataFrame(boston.data)

print bos                  #prints the entire dataSet
print "X-Vector (mXn, 13X506).....5 rows printed only......\n"
print bos.head()            #prints the initial 5 rows
print "_________________________________\n"

bos.columns = boston.feature_names      #replaces the index with assocaitive indexes for the columns

#print bos
print "_________________________________\n"
print "Y-Vector (mXn, 1X506).....\n"

print boston.target                     #the 506 y-values of each x vector
print "_________________________________\n"

bos['Price']=boston.target
#print bos.head()

lm=LinearRegression()
X=bos.drop('Price', axis=1)
lm.fit(X, bos.Price)                         #http://www.bigdataexaminer.com/2016/03/31/how-to-run-linear-regression-in-python-scikit-learn/

print "________________________________\n"
print "Vectors X and Y were passed to .fit() function intercept and parameters so obtained are"
print lm.intercept_
print lm.coef_

out=pd.DataFrame(zip(X.columns, lm.coef_),columns=['features','estimatedCoeffiecients'])


print out

plt.scatter(bos.RM, bos.Price)      #we are plotting on of feature(RM) wrt Y(price)
plt.xlabel("Avg # rooms per dwelling")
plt.ylabel("Housing Price")
plt.title("Relationship b/w Housing price and RM")
plt.show()

print lm.predict(X)     #Prints the output of hypothesis on training set
                        #Note that X is our input vector.
                        #So far we have computed the hypothesis.
                        #Now we will be predicting the same values with our hypothesis(to see the % error)

plt.scatter(bos.Price, lm.predict(X))
plt.title("Y vs Hypothesis")
plt.xlabel("Training Y")
plt.ylabel("Hypothesis Y")
plt.show()

                        #Let's see the mean squared error % , see http://www.vernier.com/til/1014/
mse=np.mean((bos.Price-lm.predict(X))**2)
print "Value of mean squared error\t",mse


            #Let's fit only one X-variable e.g ZN....mse is large

lm1=LinearRegression()
lm1.fit(X[['ZN']], bos.Price)

mse=np.mean((bos.Price-lm1.predict(X[['ZN']]))**2)
print "Value of mean squared error wrt x-variable ZN is \t",mse


X_train, X_test, Y_train, Y_test  = sklearn.cross_validation.train_test_split(
    X, bos.Price, test_size=0.10, random_state=5)

print "X-Data on which we train\t", X_train.shape
print "X-Data on which we test \t", X_test.shape
print "Y-Data on which we train \t", Y_train.shape
print "Y-Data on which we test \t", Y_test.shape

lm2=LinearRegression()
lm.fit(X_train, Y_train)
pred_train = lm.predict(X_train)
pred_test = lm.predict(X_test)

plt.scatter(pred_train, pred_train-Y_train, c="b", s=40, alpha=0.50)
plt.scatter(pred_test, pred_test-Y_test, c="g", s=40, alpha=0.50)
plt.hlines(y=0, xmin=0, xmax=50)
plt.title("Residual plot using training(blue) and test(green) data")
plt.ylabel("Residuals")
plt.show()