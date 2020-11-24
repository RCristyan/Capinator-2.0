from matplotlib import pyplot as plt
import numpy as np
import cv2

def black_final_result(black_pixel_left_count, black_pixel_right_count):
    if black_pixel_left_count > black_pixel_right_count:
        print('Tem mais pixels pretos no lado ESQUERDO')
    elif black_pixel_left_count < black_pixel_right_count:
        print('Tem mais pixels pretos do lado DIREITO')
    else:
        print('EMPATE. Ambos os lados tem a mesma quantidade de pixels pretos')

def white_final_result(white_pixel_left_count, white_pixel_right_count):
    if white_pixel_right_count < white_pixel_left_count:
        print('Tem mais pixels brancos no lado ESQUERDO')
    elif white_pixel_right_count > white_pixel_left_count:
        print('Tem mais pixels brancos do lado DIREITO')
    else:
        print('EMPATE. Ambos os lados tem a mesma quantidade de pixels brancos')

MIN_VALUE = 80 # Ajustar esse valor para se adequar a diferentes imagens
MAX_VALUE = 255

image_file = './img/antena.jpg'
img = cv2.imread(image_file,0)
_,img = cv2.threshold(img, MIN_VALUE, MAX_VALUE, cv2.THRESH_BINARY_INV)

cv2.imshow('Imagem original', img)
cv2.waitKey(2000)
cv2.destroyAllWindows()

height, width = img.shape[0], img.shape[1]

left_image = img[0:height, 0:width//2]
right_image = img[0:height, width//2:width]

pixel_total_count = cv2.countNonZero(img)
size = height * width
print(f'Total = {size} | Brancos = {pixel_total_count} | Pretos = {(size) - pixel_total_count}')

cv2.imshow('', left_image)
cv2.waitKey(2000)
cv2.destroyAllWindows()

white_pixel_left_count = cv2.countNonZero(left_image)
black_pixel_left_count = (size//2) - white_pixel_left_count

print(f'Total = {size//2} | Brancos = {white_pixel_left_count} | Pretos = {black_pixel_left_count}')

cv2.imshow('', right_image)
cv2.waitKey(2000)
cv2.destroyAllWindows()

white_pixel_right_count = cv2.countNonZero(right_image)
black_pixel_right_count = (size//2) - white_pixel_right_count
print(f'Total = {size//2} | Brancos = {white_pixel_right_count} | Pretos = {black_pixel_right_count}')

white_final_result(white_pixel_left_count, white_pixel_right_count)
black_final_result(black_pixel_left_count, black_pixel_right_count)