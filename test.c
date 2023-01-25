#include <CUnit.h>
#include <Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "Automated.h"

#include <stdio.h>  // for printf
#include "controler.h"



/* Global variables used in the tests */

Input input;



/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }

int clean_suite(void) { return 0; }

int init_suite_phase1() {
   input = init_input();
   input.state.phase = 1;
   return 0;
}

int init_suite_phase2() {
   input = init_input();
   input.state.phase = 2;
   return 0;
}

int init_suite_phase3() {
   input = init_input();
   input.state.phase = 3;
   return 0;
}

int init_suite_phase4() {
   input = init_input();
   input.state.phase = 4;
   return 0;
}



/************* Test case functions ****************/

// void test_case_sample(void)
// {
//    CU_ASSERT(CU_TRUE);
//    CU_ASSERT_NOT_EQUAL(2, -1);
//    CU_ASSERT_STRING_EQUAL("string #1", "string #1");
//    CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

//    CU_ASSERT(CU_FALSE);
//    CU_ASSERT_EQUAL(2, 3);
//    CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
//    CU_ASSERT_STRING_EQUAL("string #1", "string #2");
// }

// void test_test(void) {
//   for (int i=0; i<6; i++) {
//       CU_ASSERT(true);
//     }
// }


void test_phase1_etape1() {
   input.state.etape = 1;
   Output output;

   input.ctr_sup = false;
   output = controler(input);
   CU_ASSERT(!output.recu);
   CU_ASSERT(!output.ctr_rch);
   CU_ASSERT(output.esp_out == 0);
   CU_ASSERT(output.state.phase == input.state.phase);
   CU_ASSERT(output.state.etape == input.state.etape);
   CU_ASSERT(output.state.montant_tot == input.state.montant_tot);
   
   input.ctr_sup = true;
   output = controler(input);
   CU_ASSERT(!output.recu);
   CU_ASSERT(!output.ctr_rch);
   CU_ASSERT(output.esp_out == 0);
   CU_ASSERT(output.state.phase == input.state.phase);
   CU_ASSERT(output.state.etape == input.state.etape);
   CU_ASSERT(output.state.montant_tot == input.state.montant_tot);
}

void test_phase2_etape1() {
   input.state.etape = 1;
   Output output;


   input.boutons.but_ann = true;
   output = controler(input);
   CU_ASSERT(!output.recu);
   CU_ASSERT(!output.ctr_rch);
   CU_ASSERT(output.esp_out == 0);
   CU_ASSERT(output.state.phase == 4);
   CU_ASSERT(output.state.etape == 1);
   CU_ASSERT(output.state.montant_tot == input.state.montant_tot);

   input.boutons.but_ann = false;
   output = controler(input);
   CU_ASSERT(!output.recu);
   CU_ASSERT(!output.ctr_rch);
   CU_ASSERT(output.esp_out == 0);
   CU_ASSERT(output.state.phase == input.state.phase);
   CU_ASSERT(output.state.etape == input.state.etape);
   CU_ASSERT(output.state.montant_tot == input.state.montant_tot);
   

   
   input.boutons.but_1 = true;
   output = controler(input);
   CU_ASSERT(!output.recu);
   CU_ASSERT(!output.ctr_rch);
   CU_ASSERT(output.esp_out == 0);
   CU_ASSERT(output.state.phase == 2);
   CU_ASSERT(output.state.etape == 2);
   CU_ASSERT(output.state.montant_tot == input.state.montant_tot);

   input.boutons.but_1 = false;
   output = controler(input);
   CU_ASSERT(!output.recu);
   CU_ASSERT(!output.ctr_rch);
   CU_ASSERT(output.esp_out == 0);
   CU_ASSERT(output.state.phase == input.state.phase);
   CU_ASSERT(output.state.etape == input.state.etape);
   CU_ASSERT(output.state.montant_tot == input.state.montant_tot);
   

   
   input.boutons.but_2 = true;
   output = controler(input);
   CU_ASSERT(!output.recu);
   CU_ASSERT(!output.ctr_rch);
   CU_ASSERT(output.esp_out == 0);
   CU_ASSERT(output.state.phase == 2);
   CU_ASSERT(output.state.etape == 3);
   CU_ASSERT(output.state.montant_tot == input.state.montant_tot);

   input.boutons.but_2 = false;
   output = controler(input);
   CU_ASSERT(!output.recu);
   CU_ASSERT(!output.ctr_rch);
   CU_ASSERT(output.esp_out == 0);
   CU_ASSERT(output.state.phase == input.state.phase);
   CU_ASSERT(output.state.etape == input.state.etape);
   CU_ASSERT(output.state.montant_tot == input.state.montant_tot);
}

void test_phase2_etape2() {
   input.state.etape = 2;
   Output output;


   //TODO
}

void test_phase2_etape3() {
   input.state.etape = 3;
   Output output;


   //TODO
}

void test_phase3_etape1() {
   input.state.etape = 1;
   Output output;


   //TODO
}

void test_phase3_etape2() {
   input.state.etape = 2;
   Output output;


   //TODO
}

void test_phase3_etape3() {
   input.state.etape = 3;
   Output output;


   //TODO
}

void test_phase3_etape4() {
   input.state.etape = 4;
   Output output;


   //TODO
}

void test_phase4_etape1() {
   input.state.etape = 1;
   Output output;


   //TODO
}




/************* Test Runner Code goes here **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* test controler_phase1 */
   pSuite = CU_add_suite( "phase1", init_suite_phase1, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   if (NULL == CU_add_test(pSuite, "phase1 etape1", test_phase1_etape1 )) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   
   /* test controler_phase2 */
   pSuite = CU_add_suite( "phase2", init_suite_phase2, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   if (
      NULL == CU_add_test(pSuite, "phase2 etape1", test_phase2_etape1 ) ||
      NULL == CU_add_test(pSuite, "phase2 etape2", test_phase2_etape2 ) ||
      NULL == CU_add_test(pSuite, "phase2 etape3", test_phase2_etape3 )
   ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* test controler_phase3 */
   pSuite = CU_add_suite( "phase3", init_suite_phase3, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   if (
      NULL == CU_add_test(pSuite, "phase3 etape1", test_phase3_etape1 ) ||
      NULL == CU_add_test(pSuite, "phase3 etape2", test_phase3_etape2 ) ||
      NULL == CU_add_test(pSuite, "phase3 etape3", test_phase3_etape3 ) ||
      NULL == CU_add_test(pSuite, "phase3 etape4", test_phase3_etape4 )
   ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* test controler_phase4 */
   pSuite = CU_add_suite( "phase4", init_suite_phase4, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   if (NULL == CU_add_test(pSuite, "phase4 etape1", test_phase4_etape1 )) {
      CU_cleanup_registry();
      return CU_get_error();
   }


   // Run all tests using the basic interface
   // CU_basic_set_mode(CU_BRM_VERBOSE);
   // CU_basic_run_tests();
   // printf("\n");
   // CU_basic_show_failures(CU_get_failure_list());
   // printf("\n\n");

   // Run all tests using the automated interface
   CU_automated_run_tests();
   //CU_list_tests_to_file();

   // Run all tests using the console interface
   //CU_console_run_tests();

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}