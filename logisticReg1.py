import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sklearn

from sklearn.linear_model import LogisticRegression

trainingExample=[(0.00479616,  0.0119904,  0.00483092,  0.0120773, 1),
                 (0.51213136,  0.0113404,  0.02383092,  -0.012073, 0),
                 (0.10479096,  -0.011704,  -0.0453692,  0.0350773, 0)]

label=['x1','x2','x3','x4', 'y']

bos=pd.DataFrame.from_records(trainingExample, columns=label)

print bos

lm=LogisticRegression()
X=bos.drop('y', axis=1)

lm.fit(X, bos.y)
print lm.intercept_
print lm.coef_


out=pd.DataFrame(zip(X.columns, lm.coef_),columns=['features','estimatedCoeffiecients'])
z= np.random.randn(3, 4)
print z
print "Estimated Hypotheis Coeffs.\n", out



print lm.predict_proba(z[2])