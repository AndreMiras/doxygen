/******************************************************************************
 *
 * $Id$
 *
 * Copyright (C) 1997-1999 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * All output generated with Doxygen is not covered by this license.
 *
 */

#include "language.h"
#if !defined(ENGLISH_ONLY)
#include "translator_nl.h"
#include "translator_se.h"
#include "translator_cz.h"
#include "translator_fr.h"
#include "translator_it.h"
#include "translator_de.h"
#include "translator_jp.h"
#include "translator_es.h"
#endif

#define L_EQUAL(a) !stricmp(langName,a)

Translator *theTranslator=0;

bool setTranslator(const char *langName)
{
  if (L_EQUAL("english"))
  {
    theTranslator=new Translator;
  }
#if !defined(ENGLISH_ONLY)
  else if (L_EQUAL("dutch"))
  {
    theTranslator=new TranslatorDutch;
  }
  else if (L_EQUAL("swedish"))
  {
    theTranslator=new TranslatorSwedish;
  }
  else if (L_EQUAL("czech"))
  {
    theTranslator=new TranslatorCzech;
  }
  else if (L_EQUAL("french"))
  {
    theTranslator=new TranslatorFrench;
  }
  else if (L_EQUAL("italian"))
  {
    theTranslator=new TranslatorItalian;
  }
  else if (L_EQUAL("german"))
  {
    theTranslator=new TranslatorGerman;
  }
  else if (L_EQUAL("japanese"))
  {
    theTranslator=new TranslatorJapanese;
  }
  else if (L_EQUAL("spanish"))
  {
    theTranslator=new TranslatorSpanish;
  }
#endif
  else // use the default language (i.e. english)
  {
    theTranslator=new Translator;
    return FALSE;
  }
  return TRUE;
}