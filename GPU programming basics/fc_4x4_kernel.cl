// 线程m/4,  n/4
__kernel void adreno_gemm_4x4(__global const CL_DTYPE* a,
                          __read_only image2d_t b,
                          __global const CL_DTYPE* bias,
                          __global CL_DTYPE* c,
                          const int M,
                          const int N,
                          const int K,
                          __global const CL_DTYPE* alpha) {
  const int idy = get_global_id(0) << 2;  // id: [0, M>>2) height of out == M
  const int idx = get_global_id(1);  // id: [0, N>>2) width of out == N

  if ((idx << 2) >= N || idy >= M) return;

  CL_DTYPE4 bias0 = bias ? vload4(idx, bias) : (CL_DTYPE4)0;
  CL_DTYPE16 c_v16 = (CL_DTYPE16)(bias0.s0123, bias0.s0123, bias0.s0123, bias0.s0123);
  CL_DTYPE8 a0, a1, a2, a3;
  CL_DTYPE4 b0 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, 0));
  CL_DTYPE4 b1 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, 1));
  const CL_DTYPE* A0 = a + idy * K;
  const CL_DTYPE* A1 = A0 + K;
  const CL_DTYPE* A2 = A1 + K;
  const CL_DTYPE* A3 = A2 + K;
  for (int p = 0; p < K; p += 8) {
    a0 = vload8(0, A0 + p);
    a1 = vload8(0, A1 + p);
    a2 = vload8(0, A2 + p);
    a3 = vload8(0, A3 + p);

    c_v16 = mad((CL_DTYPE16)((CL_DTYPE4)a0.s0, (CL_DTYPE4)a1.s0, (CL_DTYPE4)a2.s0, (CL_DTYPE4)a3.s0), 
            (CL_DTYPE16)(b0.s0123, b0.s0123, b0.s0123, b0.s0123), c_v16);

    b0 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, p + 2));

    c_v16 = mad((CL_DTYPE16)((CL_DTYPE4)a0.s1, (CL_DTYPE4)a1.s1, (CL_DTYPE4)a2.s1, (CL_DTYPE4)a3.s1), 
            (CL_DTYPE16)(b1.s0123, b1.s0123, b1.s0123, b1.s0123), c_v16);

    b1 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, p + 3));

    c_v16 = mad((CL_DTYPE16)((CL_DTYPE4)a0.s2, (CL_DTYPE4)a1.s2, (CL_DTYPE4)a2.s2, (CL_DTYPE4)a3.s2), 
            (CL_DTYPE16)(b0.s0123, b0.s0123, b0.s0123, b0.s0123), c_v16);

    b0 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, p + 4));

    c_v16 = mad((CL_DTYPE16)((CL_DTYPE4)a0.s3, (CL_DTYPE4)a1.s3, (CL_DTYPE4)a2.s3, (CL_DTYPE4)a3.s3), 
            (CL_DTYPE16)(b1.s0123, b1.s0123, b1.s0123, b1.s0123), c_v16);

    b1 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, p + 5));

    c_v16 = mad((CL_DTYPE16)((CL_DTYPE4)a0.s4, (CL_DTYPE4)a1.s4, (CL_DTYPE4)a2.s4, (CL_DTYPE4)a3.s4), 
            (CL_DTYPE16)(b0.s0123, b0.s0123, b0.s0123, b0.s0123), c_v16);
    b0 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, p + 6));

    c_v16 = mad((CL_DTYPE16)((CL_DTYPE4)a0.s5, (CL_DTYPE4)a1.s5, (CL_DTYPE4)a2.s5, (CL_DTYPE4)a3.s5), 
            (CL_DTYPE16)(b1.s0123, b1.s0123, b1.s0123, b1.s0123), c_v16);
    b1 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, p + 7));

    c_v16 = mad((CL_DTYPE16)((CL_DTYPE4)a0.s6, (CL_DTYPE4)a1.s6, (CL_DTYPE4)a2.s6, (CL_DTYPE4)a3.s6), 
            (CL_DTYPE16)(b0.s0123, b0.s0123, b0.s0123, b0.s0123), c_v16);
    b0 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, p + 8));

    c_v16 = mad((CL_DTYPE16)((CL_DTYPE4)a0.s7, (CL_DTYPE4)a1.s7, (CL_DTYPE4)a2.s7, (CL_DTYPE4)a3.s7), 
            (CL_DTYPE16)(b1.s0123, b1.s0123, b1.s0123, b1.s0123), c_v16);
    b1 = READ_IMG_TYPE(CL_DTYPE_CHAR, b, SAMPLER, (int2)(idx, p + 9));

  }
  vstore4(c_v16.s0123, 0, c + idy * N + (idx << 2));
  vstore4(c_v16.s4567, 0, c + (idy + 1) * N + (idx << 2));
  vstore4(c_v16.s89ab, 0, c + (idy + 2) * N + (idx << 2));
  vstore4(c_v16.scdef, 0, c + (idy + 3) * N + (idx << 2));
}
