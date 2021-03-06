/*----------------------------------------------------------------------------*
 *                                                                            *
 *                              n w - g t p v 2 c                             * 
 *    G P R S   T u n n e l i n g    P r o t o c o l   v 2 c    S t a c k     *
 *                                                                            *
 *                                                                            *
 * Copyright (c) 2010-2011 Amit Chawre                                        *
 * All rights reserved.                                                       *
 *                                                                            *
 * Redistribution and use in source and binary forms, with or without         *
 * modification, are permitted provided that the following conditions         *
 * are met:                                                                   *
 *                                                                            *
 * 1. Redistributions of source code must retain the above copyright          *
 *    notice, this list of conditions and the following disclaimer.           *
 * 2. Redistributions in binary form must reproduce the above copyright       *
 *    notice, this list of conditions and the following disclaimer in the     *
 *    documentation and/or other materials provided with the distribution.    *
 * 3. The name of the author may not be used to endorse or promote products   *
 *    derived from this software without specific prior written permission.   *
 *                                                                            *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR       *
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  *
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.    *
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,           *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT   *
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY      *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT        *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF   *
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.          *
 *----------------------------------------------------------------------------*/

#ifndef __NW_GTPV2C_MSG_PARSE_INFO_H__
#define __NW_GTPV2C_MSG_PARSE_INFO_H__

#include "NwTypes.h"
#include "NwGtpv2c.h"

/** 
 * @file NwGtpv2cMsgParseInfo.h
 * @brief This file defines APIs for to parse incoming messages.
*/

typedef struct
{
  NwU8T                 groupedIeType;
  NwU16T                mandatoryIeCount;
  NwGtpv2cStackHandleT  hStack;

  struct {
    NwU8T iePresence;
  } ieParseInfo[NW_GTPV2C_IE_TYPE_MAXIMUM][NW_GTPV2C_IE_INSTANCE_MAXIMUM];

} NwGtpv2cGroupedIeParseInfoT;

typedef struct
{
  NwU16T                msgType;
  NwU16T                mandatoryIeCount;
  NwGtpv2cStackHandleT  hStack;

  struct {
    NwU8T ieMinLength;
    NwU8T iePresence;
    NwGtpv2cGroupedIeParseInfoT* pGroupedIeInfo;
  } ieParseInfo[NW_GTPV2C_IE_TYPE_MAXIMUM][NW_GTPV2C_IE_INSTANCE_MAXIMUM];

} NwGtpv2cMsgIeParseInfoT;

#ifdef __cplusplus
extern "C" {
#endif

NwGtpv2cMsgIeParseInfoT*
nwGtpv2cMsgIeParseInfoNew(NwGtpv2cStackHandleT hStack, NwU8T msgType);

NwRcT
nwGtpv2cMsgIeParseInfoDelete(NwGtpv2cMsgIeParseInfoT* thiz);

NwRcT
nwGtpv2cMsgIeParse(NW_IN NwGtpv2cMsgIeParseInfoT* thiz, 
    NW_IN       NwGtpv2cMsgHandleT hMsg,
    NW_INOUT    NwGtpv2cErrorT     *pError);

#ifdef __cplusplus
}
#endif

#endif /* __NW_GTPV2C_MSG_PARSE_INFO_H__ */


/*--------------------------------------------------------------------------*
 *                      E N D     O F    F I L E                            *
 *--------------------------------------------------------------------------*/

