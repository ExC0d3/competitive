itree::init();
itree::update(pos, val); // pos 위치를 val
로 업데이트
val = itree::getrange(s, e); // [s, e] 구간의 대표값
namespace itree {
typedef int val_t;
const int size = 16384; // 2
의 제곱수여야
함
// 트리를 초기화할
값
//
예) 구간 최소: 0x7fFFffFF
// 구간합: 0
const val_t init_value = 0;
// 트리의
두 child
를 병합하는 함수
//
예) 구간 최소: return min(a, b);
// 구간합: return a + b;
val_t sum(val_t a, val_t b) {
	return a + b;
}
val_t itree[size * 2 + 1];
void init() {
	for (int i = 1 ; i <= size * 2 ; i++)
		itree[i] = init_value;
}
void update(int pos, val_t val) {
	pos |= size;
	itree[pos] = val;
	while (pos >>= 1)
		itree[pos] = sum(itree[pos << 1], itree[pos << 1 | 1]);
}
val_t getrange(int s, int e) { // [s, e]
	val_t ret = init_value;
	s |= size;
	e |= size;
	while (s <= e) {
		if (s & 1)
			ret = sum(ret, itree[s]);
		if ((e & 1) == 0)
			ret = sum(ret, itree[e]);
		s = (s + 1) >> 1;
		e = (e
		     - 1) >> 1;

	}
	return ret;
}
} // namespace itree