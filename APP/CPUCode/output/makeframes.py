import numpy as np
import matplotlib.pyplot as plt
import scipy.sparse as sp
import scipy.sparse.linalg as spla

T = 1000
dim = 150

fig1 = plt.figure()

dim2 = dim*dim
L = -4.0*sp.eye(dim2,dim2,k=0) + sp.eye(dim2,dim2,k=1) + sp.eye(dim2,dim2,k=-1) + sp.eye(dim2,dim2,k=dim) + sp.eye(dim2,dim2,k=-dim)
#L = (-15.0/6.0)*sp.eye(dim2,dim2,k=0) + (2.0/3.0)*sp.eye(dim2,dim2,k=1) + (2.0/3.0)*sp.eye(dim2,dim2,k=-1) + (2.0/3.0)*sp.eye(dim2,dim2,k=dim) + (2.0/3.0)*sp.eye(dim2,dim2,k=-dim)- (1.0/24.0)*sp.eye(dim2,dim2,k=-2*dim)- (1.0/24.0)*sp.eye(dim2,dim2,k=2*dim)- (1.0/24.0)*sp.eye(dim2,dim2,k=2) - (1.0/24.0)*sp.eye(dim2,dim2,k=-2)

Linv = spla.factorized(L)

x = np.linspace(0,dim-1,dim)

Tm1 = T-1
for I in range(0,T):
	outstr = str(I) + "/" + str(Tm1)
	
	print(outstr)
	fname = "LB" + str(I) + ".dat"
	f = open(fname,'r')
	line1 = f.readline()
	
	fs = np.zeros((dim,dim,9))
	for X in range(0,dim):
		for Y in range(0,dim):
			line = f.readline()
			fs[X,Y,:] = map(float,line.split(' ',9)[:9])

	#f = np.fromfile(fname,dtype=np.float64)
	#fs = np.reshape(f,(dim,dim,9))

	rho = np.sum(fs,axis=2)
	ux = fs[:,:,1] - fs[:,:,3] + fs[:,:,5] - fs[:,:,6] - fs[:,:,7] + fs[:,:,8]
	uy = fs[:,:,2] - fs[:,:,4] + fs[:,:,5] + fs[:,:,6] - fs[:,:,7] - fs[:,:,8]


	ux = ux/rho
	uy = uy/rho


	junk, xdy = np.gradient(ux)
	ydx, junk = np.gradient(uy)

	vort = xdy - ydx
	vortv = np.reshape(vort,(dim2))
	streamv = Linv(vortv)
	stream = np.reshape(streamv,(dim,dim))

	figname = fname + "stream" + ".png"
	plt.clf()
	plt.streamplot(x, x, ux, uy)
	#plt.imshow(stream,origin="lower")
	plt.axis([-6, dim+5, -6, dim+5])
	#plt.colorbar()
	#plt.show()
	plt.savefig(figname)	

	figname = fname + "vort" + ".png"
	plt.clf()
	plt.imshow(vort,origin="lower")
	plt.colorbar()
	#plt.show()
	plt.axis([-6, dim+5, -6, dim+5])
	plt.savefig(figname)	
#plt.show()

