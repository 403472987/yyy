/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.30                          *
*        Compiled Jul  1 2015, 10:50:32                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "GUI.h"
#include "value.h"
#include "malloc.h"
#include "graphyt.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0         (GUI_ID_USER + 0x01)
#define ID_BUTTON_0         (GUI_ID_USER + 0x02)
#define ID_EDIT_0         (GUI_ID_USER + 0x03)
#define ID_EDIT_2         (GUI_ID_USER + 0x05)
#define ID_BUTTON_2         (GUI_ID_USER + 0x07)
#define ID_EDIT_4         (GUI_ID_USER + 0x0A)
#define ID_BUTTON_4         (GUI_ID_USER + 0x0D)
#define ID_EDIT_8         (GUI_ID_USER + 0x12)
#define ID_BUTTON_8         (GUI_ID_USER + 0x13)

#define ID_IMAGE_0        (GUI_ID_USER + 0x14)
#define ID_IMAGE_0_IMAGE_0     0x00
extern const U8 _acImage_0[391734];

#define ID_TEXT_0         (GUI_ID_USER + 0x15)
#define ID_TEXT_1         (GUI_ID_USER + 0x16)


int Dclose=0;
// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 480, 272, 0, 0x64, 0 },
	{ IMAGE_CreateIndirect, "Image", ID_IMAGE_0, 1, 0, 480, 272, 0, 0, 0 },	//img @@@@@@@@@@@@@@@@@@@@@@@@@@@@
  { BUTTON_CreateIndirect, "Temp",  ID_BUTTON_0, 50, 70, 140, 40, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "PM2.5", ID_BUTTON_2, 50, 180, 140, 40, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "CO2",   ID_BUTTON_4, 280, 70, 140, 40, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "PM10",  ID_BUTTON_8, 280, 180, 140, 40, 0x0, 0 },
  { EDIT_CreateIndirect, "Temp",  ID_EDIT_0, 50, 20, 140, 40, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "pm2.5", ID_EDIT_2, 50, 130, 140, 40, 0, 0x64, 0 }, 
  { EDIT_CreateIndirect, "Co2",   ID_EDIT_4, 280, 20, 140, 40, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "pm10",  ID_EDIT_8, 280, 130, 140, 40, 0, 0x64, 0 },
  
	  { TEXT_CreateIndirect, "WiFi", ID_TEXT_0, 0, 0, 80, 13, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "data", ID_TEXT_1, 81, 0, 390, 13, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _GetImageById
*/
static const void * _GetImageById(U32 Id, U32 * pSize) {
  switch (Id) {
  case ID_IMAGE_0_IMAGE_0:
    *pSize = sizeof(_acImage_0);
    return (const void *)_acImage_0;
  }
  return NULL;
}
// USER START (Optionally insert additional static code)
// USER END
extern WM_HWIN CreateInputFramewin(void);
/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	 const void * pData;//img @@@@@@@@@@@@@@@@@@@@@@@@@@@@
	U32          FileSize;//img @@@@@@@@@@@@@@@@@@@@@@@@@@@@
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetText(hItem, "Environmental Assessment");
    FRAMEWIN_SetFont(hItem,GUI_FONT_COMIC24B_ASCII );//GUI_FONT_24B_ASCII
    FRAMEWIN_SetTextColor(hItem, GUI_MAKE_COLOR(0x00A00000));
	//
    // Initialization of 'Image'//img @@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_0);
    pData = _GetImageById(ID_IMAGE_0_IMAGE_0, &FileSize);
    IMAGE_SetBMP(hItem, pData, FileSize);
    //
    // Initialization of 'Temp'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
    EDIT_SetText(hItem, " ");
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

		//
    // Initialization of 'pm2.5'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_2);
    EDIT_SetText(hItem, " ");
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
		//
    // Initialization of 'Co2'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_4);
    EDIT_SetText(hItem, " ");
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
		//
    // Initialization of 'pm10'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_8);
    EDIT_SetText(hItem, " ");
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

		// USER START (Optionally insert additional code for further widget initialization)
    // USER END
		
		 //
    // Initialization of 'WiFi'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00800000));
		TEXT_SetText(hItem, "");
    //
    // Initialization of 'data'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00800000)); 
		TEXT_SetText(hItem, " ");
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Temp'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED: 
        break;
      case WM_NOTIFICATION_RELEASED:
			  	QxPra(0);
          Graphyt_demo(); // 
        break; 
      }
      break; 
    case ID_BUTTON_2: // Notifications sent by 'PM2.5'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED: 
        break;
      case WM_NOTIFICATION_RELEASED:
          QxPra(3);
          Graphyt_demo(); // 
        break; 
      }
      break;
    case ID_BUTTON_4: // Notifications sent by 'CO2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED: 
        break;
      case WM_NOTIFICATION_RELEASED:
          QxPra(7);
          Graphyt_demo(); // 
        break; 
      }
      break;
    case ID_BUTTON_8: // Notifications sent by 'PM10'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED: 
        break;
      case WM_NOTIFICATION_RELEASED:
         QxPra(5);
         Graphyt_demo(); //
        break; 
      }
      break; 
			
			//点击显示框体------------------------------------------------------------------------
	 case ID_EDIT_0: // Notifications sent by 'Temp'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED: 
        break;
      case WM_NOTIFICATION_RELEASED:
				 BjPra(0);
         CreateInputFramewin();
        break;
      case WM_NOTIFICATION_VALUE_CHANGED: 
        break; 
      }
      break;
	 case ID_EDIT_2: // Notifications sent by 'PM2.5'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED: 
        break;
      case WM_NOTIFICATION_RELEASED:
         BjPra(3);
			   CreateInputFramewin();
        break;
      case WM_NOTIFICATION_VALUE_CHANGED: 
        break; 
      }
      break;
 case ID_EDIT_4: // Notifications sent by'CO2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED: 
        break;
      case WM_NOTIFICATION_RELEASED:
         BjPra(7);
			   CreateInputFramewin();
        break;
      case WM_NOTIFICATION_VALUE_CHANGED: 
        break; 
      }
      break; 
	case ID_EDIT_8: // Notifications sent by 'PM10'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED: 
        break;
      case WM_NOTIFICATION_RELEASED:
         BjPra(5);
			   CreateInputFramewin();
        break;
      case WM_NOTIFICATION_VALUE_CHANGED: 
        break; 
      }
      break;
		}
		break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateFramewin
*/
WM_HWIN CreateFramewin(void);

WM_HWIN CreateFramewin(void) 
{
  WM_HWIN hWin, hItem;
  char *p,*p1;
	u8 Lt=0,modeT=0xff,AdrrT=DataInfo.RevAdrr;
	u32 CntT=0;
  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	
	p = mymalloc(SRAMIN, 100);
	p1 = mymalloc(SRAMIN, 100);
	Dclose=0;
	GUI_Exec();//调用该函数重绘
	
	while(1)
	{	if(modeT!=DataInfo.mode)//模式切换
		{
		  modeT=DataInfo.mode;//保存，防止每次都进入
			if(DataInfo.mode==0)//WiFi模式
			{
			  hItem = WM_GetDialogItem(hWin, ID_TEXT_0); 
				sprintf(p, "%d - WIFI", DataInfo.RevAdrr);//显示数据的最后更新的一个数据
			  TEXT_SetText(hItem, p);
				hItem = WM_GetDialogItem(hWin, ID_TEXT_1);  
			  TEXT_SetText(hItem, "");
			}
			else//采集模式
			{
			  hItem = WM_GetDialogItem(hWin, ID_TEXT_0); 
			  TEXT_SetText(hItem, "");
				hItem = WM_GetDialogItem(hWin, ID_TEXT_1);  
			  TEXT_SetText(hItem,""); 
			}
		}
		  if((DataInfo.mode==0)&&(AdrrT!=DataInfo.RevAdrr))//WiFi模式
			{
			  AdrrT=DataInfo.RevAdrr;
			  hItem = WM_GetDialogItem(hWin, ID_TEXT_0); 
				sprintf(p, "%d - WIFI", DataInfo.RevAdrr);//显示数据的最后更新的一个数据
			  TEXT_SetText(hItem, p);
				CntT=DataInfo.Wificnt=0;//计数清零
				hItem = WM_GetDialogItem(hWin, ID_TEXT_1);  
			  TEXT_SetText(hItem, ""); 
			}
			
		if((DataInfo.mode==0)&&(CntT!=DataInfo.Wificnt))//WiFi模式
			{
			  CntT=DataInfo.Wificnt;
				hItem = WM_GetDialogItem(hWin, ID_TEXT_1);
        p1=strstr((void*)DataInfo.Wifidat,"+IPD")	;	//data		
			  snprintf(p,90, "%d  :::  %s",DataInfo.Wificnt,p1);//显示数据的最后更新的一个数据
			//	 snprintf(p,60, "%d",DataInfo.Wificnt);//显示数据的最后更新的一个数据
			  TEXT_SetText(hItem, p);
			}
		GUI_Delay(100);
			
	  if(DataInfo.update==1)//有数据到来需要更新
		{
			//温度、湿度、MQ2(甲烷)、pm2.5、pm1.0、PM10、MQ7(co)、co2、TVOC
       // "Temp"
		  hItem = WM_GetDialogItem(hWin, ID_EDIT_0);Lt=0;
			//sprintf(p, "%d", DataInfo.DataBuff[Lt][DataInfo.Revnum[Lt]-1]);//显示数据的最后更新的一个数据
			sprintf(p, "%d", DataInfo.Atemp);//显示数据的最后更新的一个数据
			EDIT_SetText(hItem, p);
			
		 //   "pm2.5", ID_EDIT_2
		  hItem = WM_GetDialogItem(hWin, ID_EDIT_2);Lt=3;
			sprintf(p, "%d", DataInfo.DataBuff[Lt][DataInfo.Revnum[Lt]-1]);//显示数据的最后更新的一个数据
			EDIT_SetText(hItem, p);
			
			//"Co2",   ID_EDIT_4   
		  hItem = WM_GetDialogItem(hWin, ID_EDIT_4);Lt=7;
			sprintf(p, "%d", DataInfo.DataBuff[Lt][DataInfo.Revnum[Lt]-1]);//显示数据的最后更新的一个数据
			EDIT_SetText(hItem, p);
			
			//   "pm10",  ID_EDIT_8
		  hItem = WM_GetDialogItem(hWin, ID_EDIT_8);Lt=5;
			sprintf(p, "%d", DataInfo.DataBuff[Lt][DataInfo.Revnum[Lt]-1]);//显示数据的最后更新的一个数据
			EDIT_SetText(hItem, p);  
		  DataInfo.update=0;
		} 
	
	}
	myfree(SRAMIN,p);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
