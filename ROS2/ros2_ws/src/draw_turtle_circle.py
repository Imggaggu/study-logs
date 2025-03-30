import numpy as np
import matplotlib.pylab as plt

n=3
to_degree = 180/np.pi
to_radian = np.pi/180

gap_theta=2*np.pi/n

print(gap_theta *to_degree)

theta = [gap_theta * n for n in range(n)]

[each*to_degree for each in theta]

r=3
x=[r*np.cos(th) for th in theta]
y=[r*np.sin(th) for th in theta]

print(x)
print(y)

#plt.scatter(x,y)
#plt.axis("equal")

def calc_position (n,r):
  gap_theta = 2*np.pi/n
  theta=[gap_theta*n for n in range(n)]

  x=[r*np.cos(th) for th in theta]
  y=[r*np.sin(th)for th in theta]

  return x,y,theta

calc_position(4,3)

def draw_pos(x,y):
  plt.scatter(x,y)
  plt.axis('equal')
  plt.show()

X,Y,theta = calc_position(10,3)
draw_pos(X,Y)