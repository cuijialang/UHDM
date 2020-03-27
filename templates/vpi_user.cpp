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
 * File:   vpi_user.cpp
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */
#include <string.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "include/sv_vpi_user.h"
#include "include/vhpi_user.h"

#include "headers/uhdm_types.h"
#include "headers/containers.h"
#include "headers/vpi_uhdm.h"
#include "headers/uhdm.h"
#include "headers/Serializer.h"

<HEADERS>

using namespace UHDM;

vpiHandle vpi_handle_by_name (PLI_BYTE8    *name,
                              vpiHandle    scope) {
  return 0;
}

vpiHandle vpi_handle_by_index (vpiHandle object,
                               PLI_INT32    indx) {
  return 0;
}


s_vpi_value* String2VpiValue(const std::string& s) {
  std::string scopy = s;
  s_vpi_value* val = new s_vpi_value;
  val->format = 0;
  val->value.integer = 0;
  val->value.str = nullptr;
  if (strstr(scopy.c_str(), "INT:")) {
    scopy.erase(0,4);
    val->format = vpiIntVal;
    val->value.integer = atoi(scopy.c_str());
  } else if (strstr(scopy.c_str(), "STRING:")) {
    scopy.erase(0,7);
    val->format = vpiStringVal;
    val->value.str = strdup(scopy.c_str());
  }
  return val;
}


s_vpi_delay* String2VpiDelays(const std::string& s) {
  std::string scopy = s;
  s_vpi_delay* delay = new s_vpi_delay;
  delay->da = nullptr;
  if (strstr(scopy.c_str(), "#")) {
    scopy.erase(0,1);
    delay->da = new t_vpi_time;
    delay->no_of_delays = 1;
    delay->time_type = vpiScaledRealTime;
    delay->da[0].low  = atoi(scopy.c_str());
    delay->da[0].type = vpiScaledRealTime;
  }
  return delay;
}


std::string VpiValue2String(const s_vpi_value* value) {
  std::string result;
  if (value == nullptr)
    return result;
  switch (value->format) {
  case vpiIntVal: {
    return std::string(std::string("INT:") + std::to_string(value->value.integer));
    break;
  }
  case vpiStringVal: {
    return std::string(std::string("STRING:") + value->value.str);
    break;
  }  
  default:
    break;
  }
  return result;
}


 std::string VpiDelay2String(const s_vpi_delay* delay) {
  std::string result;
  if (delay == nullptr)
    return result;
  if (delay->da == nullptr)
    return result;
  switch (delay->time_type) {
  case vpiScaledRealTime: {
    return std::string(std::string("#") + std::to_string(delay->da[0].low));
    break;
  }
  default:
    break;
  }
  return result;
}

static vpiHandle NewHandle (UHDM_OBJECT_TYPE type, const void *object) {
  return reinterpret_cast<vpiHandle>(new uhdm_handle(type, object));
}

vpiHandle vpi_handle (PLI_INT32 type,
                      vpiHandle   refHandle) {
  const uhdm_handle* const handle = (const uhdm_handle*) refHandle;
  const BaseClass* const object = (const BaseClass*) handle->object;
  <VPI_HANDLE_BODY>
  std::cout << "VPI ERROR: Bad usage of vpi_handle" << std::endl;
  return 0;
}

vpiHandle vpi_handle_multi (PLI_INT32 type,
                            vpiHandle   refHandle1,
                            vpiHandle   refHandle2,
                            ... ) {
  return 0;
}

/* for traversing relationships */

vpiHandle vpi_iterate (PLI_INT32 type, vpiHandle refHandle) {
  const uhdm_handle* const handle = (const uhdm_handle*) refHandle;
  const BaseClass* const object = (const BaseClass*) handle->object;
  <VPI_ITERATE_BODY>
  std::cout << "VPI ERROR: Bad usage of vpi_iterate" << std::endl;
  return 0;
}

vpiHandle vpi_scan (vpiHandle iterator) {
  if (!iterator) return 0;
  uhdm_handle* handle = (uhdm_handle*) iterator;
  const void* vect = handle->object;
  <VPI_SCAN_BODY>
  return 0;
}

PLI_INT32 vpi_free_object (vpiHandle object) {
  return vpi_release_handle(object);
}

PLI_INT32 vpi_release_handle (vpiHandle object) {
  delete (uhdm_handle*) object;
  return 0;
}

/* for processing properties */

PLI_INT32 vpi_get (PLI_INT32   property,
                   vpiHandle   object) {
  if (!object) {
      std::cout << "VPI ERROR: Bad usage of vpi_get" << std::endl;
    return 0;
  }
  uhdm_handle* handle = (uhdm_handle*) object;
  BaseClass*  obj = (BaseClass*) handle->object;
  <VPI_GET_BODY>
  return 0;
}

PLI_INT64 vpi_get64 (PLI_INT32 property,
                     vpiHandle   object) {
  if (!object) {
      std::cout << "VPI ERROR: Bad usage of vpi_get64" << std::endl;
    return 0;
  }
  uhdm_handle* handle = (uhdm_handle*) object;
  BaseClass*  obj = (BaseClass*) handle->object;
  <VPI_GET_BODY>
  return 0;
}

PLI_BYTE8 *vpi_get_str (PLI_INT32 property,
                        vpiHandle   object) {
  if (!object) {
    std::cout << "VPI ERROR: Bad usage of vpi_get_str" << std::endl;
    return 0;
  }
  uhdm_handle* handle = (uhdm_handle*) object;
  BaseClass*  obj = (BaseClass*) handle->object;
  <VPI_GET_STR_BODY>
  return 0;
}


/* delay processing */

void vpi_get_delays (vpiHandle object,
                     p_vpi_delay delay_p) {
  if (!object) {
    std::cout << "VPI ERROR: Bad usage of vpi_get_delay" << std::endl;
  }
  uhdm_handle* handle = (uhdm_handle*) object;
  BaseClass*  obj = (BaseClass*) handle->object;
  delay_p->da = nullptr;
  <VPI_GET_DELAY_BODY>
}

void vpi_put_delays (vpiHandle object,
                     p_vpi_delay delay_p) {
}

/* value processing */

void vpi_get_value (vpiHandle vexpr,
                    p_vpi_value value_p) {
  if (!vexpr) {
    std::cout << "VPI ERROR: Bad usage of vpi_get_value" << std::endl;
  }
  uhdm_handle* handle = (uhdm_handle*) vexpr;
  BaseClass*  obj = (BaseClass*) handle->object;
  value_p->format = 0;
  <VPI_GET_VALUE_BODY>
}

vpiHandle vpi_put_value (vpiHandle object,
                         p_vpi_value value_p,
                         p_vpi_time time_p,
                         PLI_INT32 flags) {
  return 0;
}

void vpi_get_value_array (vpiHandle object,
                          p_vpi_arrayvalue arrayvalue_p,
                          PLI_INT32 *index_p,
                          PLI_UINT32 num) {
}

void vpi_put_value_array (vpiHandle object,
                          p_vpi_arrayvalue arrayvalue_p,
                          PLI_INT32 *index_p,
                          PLI_UINT32 num) {
}

/* time processing */

void vpi_get_time(vpiHandle object,
                  p_vpi_time time_p) {
}


PLI_INT32 vpi_get_data (PLI_INT32 id,
                        PLI_BYTE8 *dataLoc,
			PLI_INT32 numOfBytes) {
  return 0;
}

PLI_INT32 vpi_put_data (PLI_INT32 id,
                        PLI_BYTE8 *dataLoc,
			PLI_INT32 numOfBytes) {
  return 0;
}

void *vpi_get_userdata (vpiHandle obj) {
  return 0;
}

PLI_INT32 vpi_put_userdata (vpiHandle obj,
                            void *userdata) {
  return 0;
}

vpiHandle vpi_handle_by_multi_index (vpiHandle obj,
                                     PLI_INT32 num_index,
                                     PLI_INT32 *index_array) {
  return 0;
}
