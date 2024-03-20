#pragma once

#include <tinyxml2.h>

namespace Data 
{
    class CMapSystem
    {
        public:
            static CMapSystem& GetInstance()
            {
                static CMapSystem instance;
                return instance;
            }

            CMapSystem(const CMapSystem&) = delete;
            CMapSystem& operator = (const CMapSystem&) = delete;

            float GetHeight();
            float GetWidth();

            float GetMapStartX();
            float GetMapStartY();
            float GetMapEndX();
            float GetMapEndY();

            float GetViewBorderXStart();
            float GetViewBorderXEnd();
            float GetViewBorderYStart();
            float GetViewBorderYEnd();

            void Initialize(tinyxml2::XMLDocument& _pDocument);

        private:
            CMapSystem();

            float m_Height;
            float m_Width;
    };
}