#This function starts at (i,j) and uses two pointers to find maximum l

#  which gives M(i',j',l)<=k among all (i',j') such that i'>=i and i'-j'=i-j

#So we only need to use this with at least one of i,j being 1

def getbest(i,j,k):

  best=0,bad=0

  i'=i,j'=j,l=0

  while 1

    if i'+l>N or j'+l>N

      best=max(best,l)

      break

    end


    if p[i'+l]!=q[j'+l]

      bad=bad+1

    end


    if bad>k

      best=max(best,l)

      while p[i']==q[j']

        i'=i'+1,j'=j'+1,l=l-1

      end

      bad=bad-1

      i'=i'+1,j'=j'+1

    else

      l=l+1

    end

  end


  return best

end


#Here is the function which does the full job

def getbest(k)

  best=0

  for i=1 to N

    best=max(best,getbest(1,i,k),getbest(i,1,k))

  end

  return best

end