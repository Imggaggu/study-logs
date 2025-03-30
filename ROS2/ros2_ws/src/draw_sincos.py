import numpy as np
import matplotlib.pyplot as plt
class DrawSin:
  def __init__(self , amp, freq, bias, end_time):
    self.amp=amp
    self.freq=freq
    self.bias=bias
    self.end_time=end_time
  def calc_sin(self):
    self.t = np.arange (0, self.end_time , 0.01)
    return self.amp * np.sin(2*np.pi*self.freq*self.t)+self.bias
  def draw_sin(self):
    y=self.calc_sin()
    plt.figure(figsize=(12,6))
    plt.plot(self.t,y)
    plt.grid()
    plt.show()

#ds=DrawSin(1,1,0,3)
#ds.draw_sin()


class DrawSinusoudal(DrawSin):
  def calc_cos(self):
    self.t = np.arange(0,self.end_time, 0.01)
    return self.amp * np.cos(2*np.pi*self.freq*self.t)+self.bias
  
  def draw_cos(self):    
    y=self.calc_cos()
    plt.figure(figsize=(12,6))
    plt.plot(self.t,y)
    plt.grid()
    plt.show()


#dc=DrawSinusoudal(1,1,0,3)
#dc.draw_cos()

#메서드 오버라이딩
class DrawSinusoudal2(DrawSin):
  def draw_sin(self):
    y=self.calc_sin()
    plt.figure(figsize=(12,6))
    plt.plot(self.t,y)
    plt.grid()
    plt.show()
  #추가가능
    plt.title('Sin Graph')

#super의 사용
class DrawSinusoudal3(DrawSinusoudal2):
  def __init__(self,amp,freq,bias,end_time,ts):
    super().__init__(amp,freq,bias,end_time)
    self.ts=ts

  def calc_sin(self):
    self.t = np.arange (0, self.end_time , self.ts)
    return self.amp * np.sin(2*np.pi*self.freq*self.t)+self.bias


ds3=DrawSinusoudal3(1,1,0,3,0.1)
ds3.__dict__
ds3.draw_sin()