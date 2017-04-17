/*
 * All rights reserved – Nex-G Exuberant Solutions Private Limited, Noida.                                                               
 * File Name    : 3gpp_release9_mac.c                                                                                                  
 * Module Name  : mac_stub                                                                                                          
 * Project Name : LTE MAC-Procedure UE Side                                                                                                 
 * Description  : Initiation of MAC process                                                                                    
 * Author       : Virendra U, Sumit P.                      
 * Start date   : 18-03-2017                                                                                                       
 * End date     : 10-04-2017
*/

#include"3gpp_release9_mac.h"
/*
 *  Function Name	:	Main												   
 *																   
 *  Purpose		:	Body of program starts from here								   
 *																   
 *  Return Value	:	integer type value										   
 */
S32
main (S32 argc, S8 ** argv)	/*Body of program starts from here */
{
/*
 *  Function Name	:	nexg_fopen												   
 *																   
 *  Purpose		:	Use to create or open the file in varios modes  
 *								   
 *  Inputs              :       a pointer variable name of FILE structure
 *    																   
 *  Return Value	:	the pointer of type FILE on success and return NULL on failure
 */
  if ((flogptr = nexg_fopen (MAC_RECV, "w")) == NULL)	/*open file */
    {
      nexg_error ("nexg_fopen");
      return STATUS_ERROR;
    }
  else
    {
      //do nothingPRINT_PACK(flogptr)
    }
  UeOn ();
  FrequencySearch ();
  CellSearch ();
  CellSelection ();
  MIBDecoding ();
  SIBDecoding ();
  InitialRACHProcess ();
  DefaultEPSBearerSetup ();
  UeIdle ();
  UeOff ();
  nexg_fclose (flogptr);
/*
 *  Function Name	:	return()											   
 *																   
 *  Purpose		:	to return a value and give control to calling function
 * 
 * Inputs		:	User define value					   
 *																   
 *  Return Value	:	Void type value											   
 */
  return STATUS_SUCCESS;
}

/*
 * End Of the file 3gpp_release9_mac.c
*/
