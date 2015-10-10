game sum: A xor B
game calc: minimum excluded number { Possible Games }
staircase nim: 짝수 계단에 있는 것들은 전부 소용 없음. 누구든 원래 nim 상태로 복귀시킬
수 있다.
Moore's nim_k: k개씩 제거하는 nim. 2진수로 변환하고, k+1진수에서 xor 하듯이 carry 없
이 더한다.
misere nim: play exactly as if you were playing normal play nim, except if your
winning move would lead to a position that consists of heaps of size one only.
In that case, leave exactly one more or one fewer heaps of size one than the
normal play strategy recommends.