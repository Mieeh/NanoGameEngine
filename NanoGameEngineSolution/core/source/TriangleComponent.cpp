#include "../include/ecs/components/TriangleComponent.h"

#include"../include/ecs/Entity.h"
#include"../include/ecs/components/TransformComponent.h"

namespace nano { namespace ecs {

	void ecs::TriangleComponent::Start()
	{
		
	}

	void ecs::TriangleComponent::Init()
	{
		m_transform = m_owner->m_transform;
	}

	void TriangleComponent::OnStateChange(ECSStates a_newState)
	{
		if (a_newState == ECSStates::DESTROYED) {
			m_owner->SetRenderableComponent(nullptr);
		}
	}

	TriangleComponent::TriangleComponent()
	{
	}

	TriangleComponent::TriangleComponent(const math::Vector4 & a_color)
	{
		m_color = a_color;
	}

}
}
 