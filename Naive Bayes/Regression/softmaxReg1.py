#classification into k categories example

from sklearn.datasets import load_iris
from sklearn.linear_model import LogisticRegression
iris = load_iris()
X, y = iris.data[:-1,:], iris.target[:-1]
print X
print y

lm=LogisticRegression()
lm.fit(X,y)

#print lm.intercept_
#print lm.coef_

print "Predicted class %s, real class %s" % (lm.predict(iris.data[-1,:]),iris.target[-1])
print "Probabilities for each class from 0 to 2: %s" % lm.predict_proba(iris.data[-1,:])
