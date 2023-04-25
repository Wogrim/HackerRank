"""class for a 3D point with dot and cross product"""

class Points(object):
    def __init__(self, x, y, z):
        self.x, self.y,self.z = (x,y,z)
        return
    def __sub__(self, other):
        return Points(self.x-other.x,self.y-other.y,self.z-other.z)
    def dot(self, other):
        return self.x*other.x+self.y*other.y+self.z*other.z
    def cross(self, other):
        x = self.y*other.z-self.z*other.y
        y = self.z*other.x-self.x*other.z
        z = self.x*other.y-self.y*other.x
        return Points(x,y,z)
    def absolute(self):
        return pow((self.x ** 2 + self.y ** 2 + self.z ** 2), 0.5)
