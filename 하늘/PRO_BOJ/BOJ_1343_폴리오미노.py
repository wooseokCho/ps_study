form = intput()
 
form = form.replace('XXXX','AAAA')
form = form.replace('XX','BB')
 

if form.count('X') !=0:
    print( -1)
else:
    print(form)
