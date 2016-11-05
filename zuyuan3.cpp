#include
bool segment_translation(uint8_t access_target, uint32_t vaddr, uint32_t *laddr) {
	/* implement this function to perform segment translation */
	struct SegmentSelector *seg_selector;
	uint32_t rpl,cpl,dpl,limit,granu,baddr;
	switch (access_target)
	{
		case 'c':
			seg_selector = &cs;
			break;
		case 'd':
			seg_selector = &ds;
			break;
		case 's':
			seg_selector = &ss;
			break;
		default:
			return false;
	}
	cpl=read_cpl();
	rpl=seg_selector->request_privilege_level;
	dpl=gdt[seg_selector->descriptor_index].privilege_level;
	limit=(gdt[seg_selector->descriptor_index].limit_19_16<<16)+gdt[seg_selector->descriptor_index].limit_15_0;
	granu=gdt[seg_selector->descriptor_index].granularity;
	baddr=(gdt[seg_selector->descriptor_index].base_31_24<<24)+(gdt[seg_selector->descriptor_index].base_23_16<<16)+gdt[seg_selector->descriptor_index].base_15_0;
	if (granu) limit<<=12;
	if (vaddr>=limit)
	return false;
	if (dpl>=rpl && dpl>=cpl)
	{
		*laddr=baddr+vaddr;
		return true;
	}
	return false;
}


bool load_selector(struct SegmentSelector *seg_reg, uint16_t selector) {
    	/* implement this function to perform segment-level protection */
    	uint32_t dpl = (gdt+selector)->privilege_level;
    	uint32_t rpl = seg_reg->request_privilege_level;
    	uint32_t cpl = read_cpl();
    	if (dpl < rpl || dpl < cpl)
    	    return false;
    	seg_reg->request_privilege_level=0x00000003&selector;
    	seg_reg->table_indicator=(0x00000004&selector)>>2;
    	seg_reg->descriptor_index=(0xfffffff8&selector)>>3;
     	return true;
}


bool page_translation(uint8_t rw_type, uint32_t laddr, uint32_t *paddr) {
	/* implement this function to perform page translation, as well as page-level protection */
 	uint32_t cpl = read_cpl();
	uint32_t dir = laddr>>22;
	uint32_t page = (laddr>>12)&(~((~0)<<10));
	uint32_t offset = laddr&(~((~0)<<12));
   	struct PageDirectoryEntry *dir_entry = (struct PageDirectoryEntry*)(cr3.page_directory_base<<12)+dir;
   	if (!dir_entry->present)
  		return false;
    	if (cpl)
    	{
       	 	if (!dir_entry->user_supervisor)
        	return false;
        	if (rw_type == 'w' && !dir_entry->read_write)
        	return false;
    	}
    	struct PageTableEntry *page_tbl_entry= (struct PageTableEntry*)(dir_entry->page_frame<<12)+page;
    	if (!page_tbl_entry->present)
        	return false;
    	if (cpl)
    	{
        	if (!page_tbl_entry->user_supervisor)
       		return false;
        	if (rw_type == 'w' && !page_tbl_entry->read_write)
        	return false;
    	}
    	*paddr = (page_tbl_entry->page_frame<<12)+offset;
    	return true;
}


