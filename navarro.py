#Familia 1
#Importar de sympy 
import sympy as sym
from sympy import*
a=0.494117
b=0.105882
c=0.4
A=1
x,y,z,m=sym.symbols('x,y,z,m')


formula=x**a+y**b+z**c
#Meter datos de familia 1
ingreso=75000                               
restriccion=(x+y+z-ingreso)
#Cobb Douglas
cob=A*(x**a)*(y**b)*(z**c)
Lang= cob-m*(restriccion)

gasto_comidafamilia1=21000
gasto_viviendafamilia1=4500
gasto_transportefamilia1=17000
m_lam=1
#m_lam representa Lambda
cuantogastar=[gasto_comidafamilia1,gasto_viviendafamilia1,gasto_transportefamilia1,m_lam]

#Derivadas parciales
def ecuaciones (x, y, z, m):
    f1=sym.diff(Lang,x)
    f2=sym.diff(Lang,y)
    f3=sym.diff(Lang,z)
    f4=sym.diff(Lang,m)
    return f1, f2, f3, f4
ecuaciones=ecuaciones(x,y,z,m)
print (nsolve(ecuaciones,(x,y,z,m),cuantogastar))

