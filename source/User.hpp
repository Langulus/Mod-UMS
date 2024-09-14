///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Common.hpp"


///                                                                           
///   User instance                                                           
///                                                                           
struct User final : A::User, ProducedFrom<UMS> {
   LANGULUS(ABSTRACT) false;
   LANGULUS(PRODUCER) UMS;
   LANGULUS_BASES(A::User);

public:
   User(UMS*, const Neat&);

   bool Update(Time);
   void Refresh();
};