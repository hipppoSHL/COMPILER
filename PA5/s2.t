main:
	BeginFunc
	i = 0
	_t0 = i
L0:
	_t1 = i < 10
	IFZ _t1 Goto L1
	_t2 = i * 4
	_t3 = a + _t2
	_t4 = 2 * i
	_t5 = _t4 + 1
	*(_t3) = _t5
	_t6 = *(_t3)
	_t7 = i
	i = i + 1
	Goto L0
L1: 
	s = 0
	_t8 = s
	i = _t8
	_t9 = i
L2:
	_t10 = i < 10
	IFZ _t10 Goto L3
	_t11 = i
	i = i + 1
	_t12 = _t11 * 4
	_t13 = a + _t12
	s = s + *(_t13)
	_t14 = s
	Goto L2
L3: 
	PushParam s
	_t15 = LCall print
	PopParam 4
	Return 0
	EndFunc
