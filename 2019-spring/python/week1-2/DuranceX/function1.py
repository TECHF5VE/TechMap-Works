def x_sum(n):
	sum1=0
	if(n%2==0):
		x=2
		while x<=n:
			sum1=sum1+1/x
			x=x+2
		return sum1
	else:
		x=1
		while x<=n:
			sum1=sum1+1/x
			x=x+2
		return sum1
