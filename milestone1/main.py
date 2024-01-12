import numpy as np
import math

def get_point_on_vector(initial_pt, terminal_pt, distance):
    v = np.array(initial_pt, dtype=float)
    u = np.array(terminal_pt, dtype=float)
    n = v - u
    n /= np.linalg.norm(n, 2)
    point = v - distance * n

    return tuple(point)

file=open("C:/Users/Shajithrooban/Desktop/kla_workshop/milestone1/Testcase1.txt","r")

data=[0]
count=0
x=0
while True:
    count += 1
 
    # Get next line from file
    line = file.readline()
    for i in line:
        if i>='0' and i<='9':
            x=x*10+int(i);
    data.insert(count,x)
    x=0
    if count == 3:
        break

file3=open("output.txt","w")
r=int(data[1]/2)
inpt=np.array([r*math.cos(data[3]),r*math.sin(data[3])],dtype=float)
opt=np.array([math.cos(data[3]+180),math.sin(data[3]+180)],dtype=float)
d=int(data[1]/data[2])
while data[2]>0:
    ans=get_point_on_vector(inpt, opt, d)
    print(ans)
    file3.write(' '.join(map(str,ans)))
    inpt=ans
    data[2]=data[2]-1

file3.writelines('endstr')
file3.writelines('endlib')   
file3.close()




