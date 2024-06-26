#include <malloc.h>
#include "nmpp/malloc32.h"
#include "nmpp/vSupport.h"
#include "nmpp/vInit.h"
#include "nmpp/vBitwise.h"


int nmppsMallocBetterRoute()
{
	if (nmppsMallocSpec.time<nmppsMallocSpec.timeBest){
		nmppsMallocSpec.timeBest=nmppsMallocSpec.time;	
		nmppsCopy_64u( (nm64u*)nmppsMallocSpec.route, (nm64u*)nmppsMallocSpec.bestRoute, NMPPS_MALLOC_LIMIT>>4);
		return 1;
	}
	else 
		return 0;
}
void nmppsMallocSetBestRoute(int historyEnable)
{
	//static int call=0;
	//if (call==0 || historyEnable==0 )
		nmppsCopy_64u((nm64u*)nmppsMallocSpec.bestRoute,(nm64u*)nmppsMallocSpec.route,   NMPPS_MALLOC_LIMIT>>4);
	//else 
	//	nmppsMallocSetHistoryMode();
	//call++;
}
