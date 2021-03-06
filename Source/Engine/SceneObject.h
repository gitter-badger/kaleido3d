#pragma once
#include <Math/kGeometry.hpp>
#include "Camera.h"
#include <unordered_map>

namespace physx {
  class PxRigidBody;
}

namespace k3d {

	enum SOAttrib
	{
		SOA_CULLABLE,
		SOA_MOVEABLE,
		SOA_OVERLAY
	};

	///
	/// \brief The SObject
	/// \remarks When the render calls RenderNode, it will cast the render node to drawable object,
	///  then excute rendering
	///
	class SObject
	{
	public:
		typedef std::shared_ptr<SObject>             SObjPtr;
		typedef std::vector<SObjPtr>                  SOVector;
		typedef SOVector::iterator                    SOVIter;

		SObject() = default;
		virtual ~SObject();


		/* const kMath::AABB & GetBoundingBox() const override;
		 const kMath::BoundingSphere &getBoundSphere() const override;*/

		friend class AssetManager;
		friend class SceneManager;

		void          SetNodeType(int type);
		virtual int	  GetType() = 0;
						
		const kMath::AABB & GetBoundingBox() const;
		bool IsVisible();
		void SetVisible(bool visible);


		class OctreeNode   *octreeNode;

	protected:

		//  void UpdateWorldPosition();

		  /*void UpdateEnable() override;
		  void UpdatePosition() override;
		  void UpdateTransform() override;*/

	protected:

		//  SOV     m_Children;
		SOAttrib                m_Attrib;
		bool                    m_Visible;
		kMath::Vec3f            m_ObjectPosition;
		kMath::AABB             m_BoundingBox;
		kMath::BoundingSphere   m_BoundingSphere;
		kMath::Mat4f            m_ModelMatrix;
	};

}