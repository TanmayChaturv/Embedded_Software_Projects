//Code by Tanmay Chaturvedi, Smitha Bhaskar
//Credits[1]: http://cunit.sourceforge.net/screenshots.html
//Credits[2]: https://github.com/sorabhgandhi01/Interactive-Memory-Utility/blob/master/UnitTests/util_test.c

#include <stdio.h>
#include <stdlib.h>

#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
#include <CUnit/CUnit.h>
#include "../inc/circ_buf.h"

circbuf_t *ptr;
int add_test_suite();
int cu_init_func();
int cu_clean_func();
void circbuff_init_test();
void circbuff_insert_test();
void circbuff_remove_test();

int main()
{
	if( CU_initialize_registry() == CUE_NOMEMORY )
	return CU_get_error();

	if( add_test_suite() == 0 )
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode( CU_BRM_VERBOSE );
	CU_basic_run_tests();

	//CU_set_output_filename("testfile");
	CU_automated_run_tests();

	CU_cleanup_registry();
	return CU_get_error();
}

int add_test_suite(void)
{
	CU_pSuite pSuite = NULL;
	pSuite = CU_add_suite( "Unit testing Implementation", cu_init_func, cu_clean_func );

	if( pSuite == NULL )
	{
		return 0;
	}

	if( ( CU_add_test(pSuite, "Circular Buffer Init Test", circbuff_init_test) == NULL ) ||
	( CU_add_test(pSuite, "Circular Buffer Element Insert Test", circbuff_insert_test ) == NULL ) ||
	( CU_add_test(pSuite, "Circular Buffer Element Remove Test", circbuff_remove_test ) == NULL ))
	{
		return 0;
	}
	return 1;
}

int cu_init_func(void)
{
	
	ptr = (circbuf_t *)malloc(sizeof(circbuf_t));
	return 0;
}

int cu_clean_func(void)
{
	free(ptr);
	return 0;
}


void circbuff_init_test(void)
{

	/*Checking if pointer not null*/
	CU_ASSERT_PTR_NOT_NULL(ptr);
	/*Checking if circbuf init working*/
	CU_ASSERT_EQUAL(buff_init(ptr,4),2);
	/*Checking if circbuf init not working with buf len = 0*/
	CU_ASSERT_NOT_EQUAL(buff_init(ptr,0),2);
	/*Checking if circbuf init not working with buf len = -1*/
	CU_ASSERT_EQUAL(buff_init(ptr,-1),3);
}


void circbuff_insert_test(void)
{
	/*Checking if circbuf element insert working*/
	CU_ASSERT_EQUAL(buff_insert(ptr,1),4);
	/*Checking if circbuf element insert working with element's min value, ie 0*/
	CU_ASSERT_EQUAL(buff_insert(ptr,0),4);
	/*Checking if circbuf element insert working with element's max value, ie 255*/
	CU_ASSERT_EQUAL(buff_insert(ptr,255),4);
	/*Checking if circbuf element insert working with non-zero element value, ie -100*/
        CU_ASSERT_EQUAL(buff_insert(ptr,-100),4);
	/*Checking if circbuf element insert NOT working for more than 4 elements*/
        CU_ASSERT_EQUAL(buff_insert(ptr,5),5);
        CU_ASSERT_EQUAL(buff_insert(ptr,6),5);
	

}

void circbuff_remove_test(void)
{
	CU_ASSERT_EQUAL(buff_remove(ptr),6);
	CU_ASSERT_EQUAL(buff_remove(ptr),6);
	CU_ASSERT_EQUAL(buff_remove(ptr),6);
        CU_ASSERT_EQUAL(buff_remove(ptr),6);
	/*Checking if circbuf element remove NOT working for more than 4 elements*/
	CU_ASSERT_EQUAL(buff_remove(ptr),7);
}
