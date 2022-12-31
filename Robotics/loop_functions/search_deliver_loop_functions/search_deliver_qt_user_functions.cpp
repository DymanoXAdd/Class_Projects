#include "search_deliver_qt_user_functions.h"
#include <controllers/search_deliver/search_deliver.h>
#include <argos3/core/simulator/entity/controllable_entity.h>

using namespace argos;

/****************************************/
/****************************************/

CSearchDeliverQTUserFunctions::CSearchDeliverQTUserFunctions() {
   RegisterUserFunction<CSearchDeliverQTUserFunctions,CFootBotEntity>(&CSearchDeliverQTUserFunctions::Draw);
}

/****************************************/
/****************************************/

void CSearchDeliverQTUserFunctions::Draw(CFootBotEntity& c_entity) {
   CFootBotSearchDeliver& cController = dynamic_cast<CFootBotSearchDeliver&>(c_entity.GetControllableEntity().GetController());
   CFootBotSearchDeliver::SFoodData& sFoodData = cController.GetFoodData();
   if(sFoodData.HasFoodItem) {
      DrawCylinder(
         CVector3(0.0f, 0.0f, 0.3f), 
         CQuaternion(),
         0.1f,
         0.05f,
         CColor::BLACK);
   }
}

/****************************************/
/****************************************/

REGISTER_QTOPENGL_USER_FUNCTIONS(CSearchDeliverQTUserFunctions, "search_deliver_qt_user_functions")
