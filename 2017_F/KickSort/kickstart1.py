def solve(N, A):
    bad = [0]
    def kick(A):
        if len(A) <= 1: return
        B, C = [], []
        ix = (len(A) - 1)/2
        P = A[ix]
        for i, x in enumerate(A):
            if i == ix: continue
            (B if x <= P else C).append(x)
        bad[0] += not B or not C
        kick(B)
        kick(C)
    kick(A)
    return "YES" if bad[0] == N-1 else "NO"

###
def main():
    with open('in.txt','r') as fi, \
            open('out.txt', 'w') as fo:
        rr = lambda: fi.readline().strip()
        rrM = lambda: map(int,rr().split())
        for tc in xrange(1, 1 + int(rr())):
            N = int(rr())
            A = rrM()
            zeta = solve(N, A)
            outstr = "Case #%i: " % tc + str(zeta)
            print outstr
            fo.write(outstr+'\n')
            
if __name__ == "__main__": main()
