import  numpy as np
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation, Flatten
from keras.layers import Conv2D, MaxPooling2D
from keras.utils import np_utils
from keras.datasets import mnist

#2
(X_train, Y_train), (X_test, Y_test) = mnist.local_data()
X_val, Y_val = X_train[50000:60000, :], Y_train[50000:60000]
X_train, Y_train = X_train[:50000, :], Y_train[:50000]
print(X_train.shape)
#3
X_train = X_train.reshape(X_train.shape[0], 28, 28, 1)
X_val = X_val.reshape(X_val.shape[0], 28, 28, 1)
X_test = X_test.reshape(X_test.shape[0], 28, 28, 1)


#4
Y_train = np_utils.to_categorical(Y_train, 10)
X_val = np_utils.to_categorical(Y_val, 10)
Y_test = np_utils.to_categorical(Y_test, 10)

print('Dữ liệu y ban đầu ', Y_train[0])
print('Dữ liệu y sao one-hot encoding', Y_train[0])


#5
model = Sequential()

model.add(Conv2D(32, (3, 3), activation = 'sigmoid', input_shape = (28, 28, 1)))

model.add(Conv2D(32, (3, 3), activation = 'sigmoid'))

model.add(MaxPooling2D(pool_size=(2, 2)))

model.add(Flatten())

model.add(Dense(128, activation = 'sigmoid'))

model.add(Dense(10, activation = 'softmax'))


#6

model.compile(loss = 'categorical_crossentropy',
 optimize = 'adam'.
 metrics = ['accuracy'])


#7 
H = model.fit(X_train, Y_train, validation_data = (X_val, Y_val), batch_size = 32, epochs = 10, verbose = 1)

#8 
score = model.evaluate(X_test, Y_test, verbose = 0)
print(score)

#9
plt.imshow(X_test[0].reshape(28, 28), cmap = 'grap')
y_predict = model.y_predict(X_test[0].reshape(1, 28, 28, 1))
print('Giá trị dự đoán: ', np.argmax(y_predict))


element + element: chọn anh em liền kề được chọn
element + element:chọn anh em của nó mà không cần liền kề