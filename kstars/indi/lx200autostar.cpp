/*
    LX200 Autostar
    Copyright (C) 2003 Jasem Mutlaq

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lx200autostar.h"
#include "lx200driver.h"


extern LX200Generic *telescope;
extern int MaxReticleFlashRate;
extern char mydev[];

static IText   VersionDate	 = { mydev, "Version Date", NULL, ILS_IDLE};
static IText   VersionTime       = { mydev, "Version Time", NULL, ILS_IDLE};
static IText   VersionNumber     = { mydev, "Version Number", NULL, ILS_IDLE};
static IText   FullVersion	 = { mydev, "Full Version", NULL, ILS_IDLE};
static IText   ProductName       = { mydev, "Product Name", NULL, ILS_IDLE};

#ifdef LX200_AUTOSTAR
void
ISInit()
{
	fprintf(stderr , "initilizaing from autostar device...\n");

	// Two important steps always performed when adding a sub-device

	// 1. mydev = device_name
	strcpy(mydev, "LX200Autostar");
	// 2. device = sub_class
	telescope = new LX200Autostar();

	// Misc. device-specific settings
	MaxReticleFlashRate = 9;
}

#endif

LX200Autostar::LX200Autostar() : LX200Generic()
{

  VersionDate.text	= new char[16];
  VersionTime.text	= new char[16];
  FullVersion.text	= new char[64];
  VersionNumber.text	= new char[16];
  ProductName.text	= new char[32];

}

void LX200Autostar::ISGetProperties (char *dev)
{

if (dev && strcmp (mydev, dev))
    return;

// process parent first
if (callParent)
    LX200Generic::ISGetProperties(dev);
else
   callParent = 1;

ICDefText (&VersionNumber, "Version Number", IP_RO);
ICDefText (&VersionTime  , "Version Time", IP_RO);
ICDefText (&VersionDate  , "Version Date", IP_RO);
ICDefText (&FullVersion  , "Full Version", IP_RO);
ICDefText (&ProductName  , "Product Name", IP_RO);

}

void LX200Autostar::ISNewText (IText *t)
{
  if (callParent)
      LX200Generic::ISNewText(t);
  else
     callParent = 1;




}

void LX200Autostar::ISNewNumber (INumber *n)
{
  if (callParent)
      LX200Generic::ISNewNumber(n);
  else
      callParent = 1;
 }

 void LX200Autostar::ISNewSwitch (ISwitches *s)
 {

    if (callParent)
        LX200Generic::ISNewSwitch(s);
    else
       callParent = 1;



 }

 void LX200Autostar::ISPoll ()
 {

   if (callParent)
      LX200Generic::ISPoll();
   else
      callParent =1;





 }

 void LX200Autostar::getBasicData()
 {

   // process parent first
   if (callParent)
      LX200Generic::getBasicData();
   else
      callParent = 1;

   getVersionDate(VersionDate.text);
   getVersionTime(VersionTime.text);
   getVersionNumber(VersionNumber.text);
   getFullVersion(FullVersion.text);
   getProductName(ProductName.text);

   ICSetText(&VersionDate, NULL);
   ICSetText(&VersionTime, NULL);
   ICSetText(&VersionNumber, NULL);
   ICSetText(&ProductName, NULL);
   ICSetText(&FullVersion, NULL);

 }
