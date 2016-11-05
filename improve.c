
float * descr;

float vl_correl(float const * x, float const * y)
{
	float dotpro = 0;
	float normx = 0, normy = 0;
	for (int i = 0; i < 8; i ++)
	{
		dotpro += *(x + i) * *(y + i);
		normx += *(x + i) * *(x + i);
		normy += *(y + i) * *(y + i);
	}
	normx = sqrt(normx); normy = sqrt(normy);
	return dotpro / (normx * normy);
}
float const *
vl_dsift_get_descriptors_improve (VlDsiftFilter const *self)
{
	if (descr) {
		vl_free(descr);
	}
	int numFrameAlloc = vl_dsift_get_keypoint_num (self) ;
    int numBinAlloc   = vl_dsift_get_descriptor_size (self) ;
	descr = vl_malloc(sizeof(float) * numBinAlloc * numFrameAlloc) ;
	
	float * head = self->descrs;
	float * descrIter = descr ;
	for (int p = 0; p < numFrameAlloc; p ++) {
		for (int i = 0; i < numBinAlloc; i ++)
			*descrIter ++ = *(head + i);
		for (int i = 0; i < 16; i ++) {
			for (int j = i + 1; j < 16; j ++) {
				*descrIter ++ = vl_correl(head + i * 8, head + j * 8);
			}
		}
		head += numBinAlloc;
	}
	vl_free(head);
	vl_free(descrIter);
	return descr ;
}