/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   <GROUPNAME>.cpp
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */


#include <iostream>
#include "headers/uhdm.h"
#include "<GROUPNAME>.h"

namespace UHDM {

  bool <GROUPNAME>GroupCompliant(any* item) {
    BaseClass* the_item = (BaseClass*) item;
    unsigned int uhdmtype = the_item->getUhdmType();
    if (<CHECKTYPE>) {
      std::cout << "Internal Error: adding wrong object type (" << getUhdmName(uhdmtype) << ") in a <GROUPNAME> group!\n";   
      return false;
    }
    return true;
  }

  bool <GROUPNAME>GroupCompliant(VectorOfany* vec) {
    for (auto item : *vec) {
      if (!<GROUPNAME>GroupCompliant(item)) {
	return false;
      }
    }
    return true;
  }
 	     
};
