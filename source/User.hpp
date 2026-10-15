///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Export.hpp"
#include <Langulus/Producible.hpp>


///                                                                           
///   User instance                                                           
///                                                                           
struct User final : Things::User, ProducedFrom<UMS> {
   using CTTI_Abstract  = No;
   using CTTI_Producer  = UMS;
   using CTTI_Bases     = Things::User;

public:
   User(UMS*, Many const&);

   bool Update(Time);
   void Refresh();
};