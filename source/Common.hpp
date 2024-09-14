///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include <Langulus.hpp>
#include <Langulus/User.hpp>                        
#include <Flow/Factory.hpp>

using namespace Langulus;

struct UMS;
struct User;

#if 0
   #define VERBOSE_ENABLED() 1
   #define VERBOSE(...)      Logger::Verbose(Self(), __VA_ARGS__)
   #define VERBOSE_TAB(...)  const auto tab = Logger::VerboseTab(Self(), __VA_ARGS__)
#else
   #define VERBOSE_ENABLED() 0
   #define VERBOSE(...)      LANGULUS(NOOP)
   #define VERBOSE_TAB(...)  LANGULUS(NOOP)
#endif