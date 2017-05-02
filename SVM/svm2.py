import matplotlib.pyplot as plt
import csv
from textblob import TextBlob
import pandas
import sklearn
import cPickle
import numpy as np
from sklearn.feature_extraction.text import CountVectorizer, TfidfTransformer
from sklearn.naive_bayes import MultinomialNB
from sklearn.svm import SVC, LinearSVC
from sklearn.metrics import classification_report, f1_score, accuracy_score, confusion_matrix
from sklearn.pipeline import Pipeline
from sklearn.grid_search import GridSearchCV
from sklearn.cross_validation import StratifiedKFold, cross_val_score, train_test_split 
from sklearn.tree import DecisionTreeClassifier 
from sklearn.learning_curve import learning_curve


#messages = [line.rstrip() for line in open('datasetSVM')]

#for message_no, message in enumerate(messages[:10]):		#to print first 10 messages 
 #   print message_no, message

    					# to convert the tsv to panda library variable
messages = pandas.read_csv('datasetSVM2.txt', sep='\t', quoting=csv.QUOTE_NONE,
                           names=["label", "message"])

#In order to view the aggregrate statistics in pandas

print type(messages)
print messages.groupby('label').describe()

print (messages['label'])


#How long are the messages
#messages['length'] = messages['message'].map(lambda text: len(text))
print messages.head()


#messages.length.describe()


#this will split a message into its individual words:
def split_into_tokens(message):
    message = unicode(str(message), 'utf8')  # convert bytes into proper unicode
    return TextBlob(message).words

messages.message.head()

print messages.message.head().apply(split_into_tokens)

def split_into_lemmas(message):
    message = unicode(str(message), 'utf8').lower()
    words = TextBlob(message).words
    # for each word, take its "base form" = lemma 
    return [word.lemma for word in words]

bow_transformer = CountVectorizer(analyzer=split_into_lemmas).fit(messages['message'])
print len(bow_transformer.vocabulary_)

message4 = messages['message'][3]
print message4

bow4 = bow_transformer.transform([message4])
print bow4

print bow4.shape

print bow_transformer.get_feature_names()[10]
print bow_transformer.get_feature_names()[15]



messages_bow = bow_transformer.transform(messages['message'])
print 'sparse matrix shape:', messages_bow.shape
print 'number of non-zeros:', messages_bow.nnz
print 'sparsity: %.2f%%' % (100.0 * messages_bow.nnz / (messages_bow.shape[0] * messages_bow.shape[1]))


tfidf_transformer = TfidfTransformer().fit(messages_bow)
tfidf4 = tfidf_transformer.transform(bow4)
print tfidf4


#What is the IDF (inverse document frequency) of the word "u"? Of word "university"?
#print tfidf_transformer.idf_[bow_transformer.vocabulary_['summit']]
#print tfidf_transformer.idf_[bow_transformer.vocabulary_['business']]

messages_tfidf = tfidf_transformer.transform(messages_bow)
print messages_tfidf.shape


msg_train, msg_test, label_train, label_test = \
    train_test_split(messages['message'], messages['label'], test_size=0.2)


print len(msg_train), len(msg_test), len(msg_train) + len(msg_test)


pipeline_svm = Pipeline([
    ('bow', CountVectorizer(analyzer=split_into_lemmas)),
    ('tfidf', TfidfTransformer()),
    ('classifier', SVC()),  # <== change here
])


# pipeline parameters to automatically explore and tune
param_svm = [
  {'classifier__C': [1, 10, 100, 1000], 'classifier__kernel': ['linear']},
  {'classifier__C': [1, 10, 100, 1000], 'classifier__gamma': [0.001, 0.0001], 'classifier__kernel': ['rbf']},
]

print "Hi there"

grid_svm = GridSearchCV(
    pipeline_svm,  # pipeline from above
    param_grid=param_svm,  # parameters to tune via cross validation
    refit=True,  # fit using all data, on the best detected classifier
    n_jobs=-1,  # number of cores to use for parallelization; -1 for "all cores"
    scoring='accuracy',  # what score are we optimizing?
    cv=StratifiedKFold(label_train, n_folds=5),  # what type of cross validation to use
)

print "Hi there"

svm_detector = grid_svm.fit(msg_train, label_train) # find the best combination from param_svm
print svm_detector.grid_scores_


print "Predicting"

print "Original : education\nPredicted : "
print svm_detector.predict(["your deadlin sunday hope enjoy week comput want send quick remind assign due sunday april pdt still got day submit assign stay track good luck"])[0]
print "Original : Business\nPredicted : "
print svm_detector.predict(["hello abhishek sah would like inform order isar deliveri you receiv shipment end day your packag ship amazon transport servic track pleas note signatur requir deliveri packag one avail sign packag may wish make altern deliveri arrang carrier"])[0]
print "Original : education\nPredicted : "
print svm_detector.predict(["whi let know our secur system detect log locat may simpli network configur chang log new physic locat could also mean somebodi els access account recogn activ log account set account set secur audit log see locat list recommend chang password want add extra secur account tri lastpass authent logmein twofactor authent app add addit layer secur unauthor access regard logmein team"])[0]
print "Original : business\nPredicted : "
print svm_detector.predict(["financi posit concern person resourc avail examin net worth household cash flow net worth person balanc sheet calcul asset person control minu liabil household one point time household cash flow total expect sourc incom within year minu expect expens within year from analysi financi planner determin degre time person goal adequ protect analysi protect household risk these risk divid follow liabil properti death disabl health long term care some risk may selfinsur requir purchas insur contract determin much insur get cost effect term requir knowledg market person insur busi owner athlet entertain requir special insur adequ protect sinc insur also enjoy tax benefit util insur invest product may critic piec overal invest plan tax plan typic incom tax singl largest expens household manag tax question pay tax much govern give mani incent form tax deduct credit use reduc lifetim tax burden most modern govern use progress tax typic one incom grow higher margin rate tax must paid take advantag myriad tax break plan one person financ make signific impact later save money long term invest accumul goal plan accumul enough money larg purchas life event peopl consid financi plan major reason accumul asset includ purchas hous car start busi pay educ expens save retir achiev goal requir project cost need withdraw fund necessari abl achiev goal major risk household achiev accumul goal rate price increas time inflat use net present valu calcul financi planner suggest combin asset earmark regular save invest varieti invest order overcom rate inflat invest portfolio get higher rate return typic subject portfolio number risk manag portfolio risk often use asset alloc seek diversifi invest risk opportun thi asset alloc prescrib percentag alloc invest stock either prefer stock common stock bond exampl mutual bond govern bond corpor bond cash altern invest the alloc also take consider person risk profil everi investor sinc risk attitud vari person person retir plan process much cost live retir come plan distribut asset meet incom shortfal method retir plan includ take advantag govern allow structur manag tax liabil includ individu ira structur employ sponsor retir plan estat plan involv plan disposit one asset death typic tax due state feder govern one death avoid tax mean one asset distribut one heir one leav one asset famili friend charit group "])[0]
print "Original : business\nPredicted : "
print svm_detector.predict(["capit financi sens money give busi power buy good use product good offer servic the capit two type resourc equiti debt the deploy capit decid budget thi may includ object busi target set result financi term target set sale result cost growth requir invest achiev plan sale financ sourc invest budget may long term short term long term budget time horizon year give vision compani short term annual budget drawn control oper year budget includ propos fix asset requir financ capit budget often adjust annual done everi year part capit improv plan cash budget also requir the work capit requir busi monitor time ensur suffici fund avail meet shortterm expens the cash budget basic detail plan show expect sourc use cash come spend appropri the cash budget follow six main section begin cash balanc contain last period close cash balanc word remain cash last year earn cash collect includ expect cash receipt sourc cash period consid mainli sale cash disburs list plan cash outflow period dividend exclud interest payment shortterm loan appear financ section all expens affect cash flow exclud list depreci amort etc cash excess defici function cash need cash avail cash need determin total cash disburs plu minimum cash balanc requir compani polici total cash avail less cash need defici exist financ disclos plan borrow repay plan borrow includ interest "])[0]
print "Original : business\nPredicted : "
print svm_detector.predict(["ashwani gujral told think infosi worth trade structur problem even guidanc percent higher two month later come back revis guidanc think better trade nbfc capit first etc make new high bajaj finserv mess around space bodi languag thisthat five thing watch even result good bad think pretti much worth ignor think capit first buy stop loss target repco home financ well buy stop loss target jbf industri buy stop loss target bharat financi inclus get sort seriou declin problem micro financ compani one end nbfc want sell stop loss target sonata softwar also sell stop loss target petronet lng fresh breakout market kind sideway would think seem like petronet "])[0]
print "Original : business\nPredicted : "
print svm_detector.predict(["the march quarter earn start mute note infosi deliv belowpar sequenti perform revenu margin miss street estim there plenti headwind second largest softwar export enter anoth year low growth environ usd revenu rose percent qoq basi flat revenu constant currenc term reflect pressur retail percent qoq healthcar percent qoq vertic suggest expert the stock slip sharpli thursday said revenu growth guidanc percent miss street expect percent the manag given conserv revenu guidanc percent constant currenc term also lower ebit margin guidanc percent cite visa concern higher invest offshor cross currenc impact infosi stock close percent lower thursday broke exponenti move averag dema the indic also show downtrend stock macd alreadi given sell back month march look like trend sharpli downsid make sens investor get infosi plan sell stock near term good buy investor plan stay stock year valuat look inexpens thing easi softwar giant worri like higher visa cost currenc headwind slowdown growth continu weigh price expect stronger rupe dollar advers environ visa remain key concern saji john research analyst geojit financi servic told "])[0]
print "Original : Education\nPredicted : "
print svm_detector.predict(["naac ask rework accredit process higher educ institut manash pratim gohain tnn updat apr ist highlight the hrd ministri ask naac work toward bring transpar object technolog grade system per new peer team assess institut given weightag instead current decid grade institut union hrd minist prakash javadekar toi file photo union hrd minist prakash javadekar toi file photo new delhi away corrupt subject assess grade higher educ institut ministri human resourc develop ask complet overhaul accredit process nation assess accredit council naac juli follow complaint corrupt council peer team ministri ask naac work toward bring transpar object technolog grade system per new peer team assess institut given weightag instead current decid grade institut moreov institut know advanc team visit accommod travel plan peer team visit outsourc top comment most indian univers produc scrap name educ wast public major weightag grade decid base technic object input via use inform commun technolog ict these mani chang said offici pipelin accredit process higher educ institut order bring transpar object technolog assess grade there complaint institut conduct assessor part peer team therefor union hrd minist prakash javadekar taken person interest qualit improv grade system said senior offici"])[0]
print "Original : Education\nPredicted : "
print svm_detector.predict(["there post assist professor lie vacant govern colleg univers deputi chief minist dinesh sharma also hold higher educ portfolio said the exempt fill vacant seat hand enhanc qualiti teach higher educ institut per ugc regul minimum qualif appoint teacher academ staff univers measur mainten standard higher educ amend date may commiss state degre candid regist phd programm prior juli govern provis ordin institut award degre time candid exempt net recruit appoint assist professor univers colleg"])[0]
print "Original : business\nPredicted : "
print svm_detector.predict(["what read week india face huge dearth invest compani ist post comment credit card debt roughli half size gdp the feder reserv report last week collect credit card debt reach trillion roughli half size gdp peopl like credit card much use even tiniest purchas accord new survey releas week credit card site among peopl credit card per cent said use buy item read http"])[0]
print "Original : Education\nPredicted : "
print svm_detector.predict(["suprem court stay decis fix upper age limit year neet amit anand choudhari tnn mar ist new delhi all medic aspir student appear neet year irrespect age suprem court friday stay cbse decis fix upper age limit year take entranc examin mbb cours bench justic dipak misra said decis taken central board secondari educ fix upper age limit administr instruct medic council india seem wrong student bar appear entranc examin right side the court direct cbse allow student appli examin ask open window till april fill form the last date fill form expir march entranc test schedul may the bench agre submiss aggriev student contend decis taken board illeg rule regul fix upper age limit medic entranc examin senior advoc amrendra sharan indu malhotra appear student told bench got affect due age restrict plead court allow appear neet prima faci find age limit could determin way notic basi instruct issu medic council india appropri direct desir candid allow fill form onlin portal cbse april ani form submit beyond april shall accept bench said the court ask cbse take step make arrang allow affect student appear entranc test provid addit centr accommod collector concern district citi whoever author extend support form accept examin held date fix make differ centr avail bench said latest comment year age limit neet war fair enough old well younger student student gener clear cbse around year age year window clear neet fair read morescl premi note high court pass order contrari present order cbse shall bound order pass court far cutoff date concern high court countri shall interfer regard litig pertain centr court said"])[0]
