///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Common.hpp"
#include <Langulus/Flow/Producible.hpp>


///                                                                           
///   User instance                                                           
///                                                                           
struct User final : A::User, ProducedFrom<UMS> {
   using CTTI_Abstract = No;
   using CTTI_Producer = UMS;
   LANGULUS_BASES(A::User);

public:
   User(UMS*, Many const&);

   bool Update(Time);
   void Refresh();
};