/* expand the normal dsift*/
#include "mex.h"
#include <math.h>

#define ebs 0.0000001
#define afa 1 / 60
float vl_correl(double* x, double* y)
{
    double xx = 0, yy = 0, xy = 0, sumx = 0, sumy = 0;
    int i;
    for (i = 0; i < 8; i ++)
    {
        xy += *(x + i) * *(y + i);
        xx += *(x + i) * *(x + i);
        yy += *(y + i) * *(y + i);
        sumx += *(x + i);
        sumy += *(y + i);
    }
    double t1, t2, t3;
    t1 = 8 * xy - sumx * sumy;
    t2 = sqrt(8 * xx - sumx * sumx);
    t3 = sqrt(8 * yy - sumy * sumy);
    if (t2 < ebs || t3 < ebs) return 0;
    else return t1 / (t2 * t3) * afa;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *inData;
    double *outData;
    int M, N, i, j, p;
    inData = mxGetPr(prhs[0]);
    M = mxGetM(prhs[0]);
    N = mxGetN(prhs[0]);
    plhs[0] = mxCreateDoubleMatrix(M + 120, N, mxREAL);
    outData = mxGetPr(plhs[0]);

    for (p = 0; p < N; p ++)
    {
        for (i = 0; i < M; i ++)
        {
            *outData ++ = *(inData + i);
        }
        for (i = 0; i < 16; i ++)
            for (j = i + 1; j < 16; j ++)
            {
                *outData ++ = vl_correl(inData + i * 8, inData + j * 8);
            }
        inData += M;
    }
}
