#pragma once

#include "../data/data.commandAction.h"

namespace Logic 
{
    class CCommand 
    {
        public:
            CCommand();
            ~CCommand();

        public:
            Data::SCommandAction::EActions GetType() const;
            void SetType(Data::SCommandAction::EActions _Type);

        private:
            Data::SCommandAction::EActions type;
    };
}