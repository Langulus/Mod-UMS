///                                                                           
/// Langulus::Module::UMS                                                     
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "User.hpp"
#include <Langulus/Factory.hpp>
#include <Langulus/Verbs/Create.hpp>


///                                                                           
///   User management system module                                           
struct UMS final : Things::UserModule {
   using CTTI_Abstract  = No;
   using CTTI_Bases     = Things::UserModule;
   using CTTI_Ability   = Verbs::Create;

private:
   TFactory<User> mUsers;

public:
   UMS(Runtime*, Neat const&);

   bool Update(Time);
   void Create(Verb&);
   void Teardown();
};