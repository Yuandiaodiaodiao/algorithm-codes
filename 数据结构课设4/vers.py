with open('out.txt','r') as f:
    k=int(f.readline())
    blocks=[]
    for i in range(1<<k):
        x=f.readline().replace('\n','').replace('     ',' ').strip().split(' ')
        blocks.append([x for x in map(int,x)])
    colors=[]
    for i in range(1 << k):
        x = f.readline().replace('\n', '').replace('     ',' ').strip().split(' ')
        colors.append([x for x in map(int,x)])



print(blocks)
print(colors)
import cv2
import numpy as np
from matplotlib import pyplot as plt
img = np.zeros((1024,1024,3), np.uint8)
img.fill(255)
lens=30
for i in range(1<<k):
    for j in range(1 << k):
        if colors[i][j]==1:
            colx=(240,50,0)
        elif colors[i][j]==2:
            colx=(0,240,50)
        elif colors[i][j]==3:
            colx=(50,0,240)
        else:
            colx=(125,0,0)
        cv2.rectangle(img, (i * lens, j * lens), (i * lens + int(lens / 1), j * lens + int(lens / 1)),
                      (200, 200, 200), thickness=-1)
        cv2.rectangle(img,(i*lens+1,j*lens+1),(i*lens+int(lens/1)-2,j*lens+int(lens/1)-2),colx,thickness=-1)



cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()