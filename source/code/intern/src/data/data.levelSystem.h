#pragma once

#include <string>

namespace Data 
{
    class CLevelSystem
    {
        public:
            static CLevelSystem& GetInstance()
            {
                static CLevelSystem instance;
                return instance;
            };

            int GetSelectedLevel() const;
            void SetSelectedLevel(int _Level);

            std::string GetSelectedLevelAsString();
            std::string GetSelectedLevelFileName();

        private:
            CLevelSystem();

            CLevelSystem(const CLevelSystem&) = delete;
            CLevelSystem& operator = (const CLevelSystem&) = delete;

            int m_SelectedLevel;
    };
}