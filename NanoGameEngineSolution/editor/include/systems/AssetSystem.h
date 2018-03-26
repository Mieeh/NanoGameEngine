#pragma once

#include"EditorSystem.h"
#include<vector>

namespace nano {
	namespace asset {
		class Asset;
		class ImageAsset;
		class SoundAsset;
} }

namespace nano { namespace editor {  

	class AssetSystem : public EditorSystem<AssetSystem> {
		friend class EditorSystem<AssetSystem>;
	private:
		AssetSystem() { }

		//std::vector<asset::Asset*> m_assetContainer;
		std::vector<asset::ImageAsset*> m_imageAssetContainer;
		std::vector<asset::SoundAsset*> m_soundAssetContainer;
		asset::ImageAsset *m_highlightTextureAsset;

		// Helper
		void ReadDirectory(const std::string& name, std::vector<std::string>& v);

	public:
		void Start() override;
		void Update() override;
		void Quit() override;

		//std::vector<asset::Asset*>& getAssetContainer();
		std::vector<asset::ImageAsset*> &getImageAssetContainer();
		std::vector<asset::SoundAsset*> &getSoundAssetContainer();
		asset::ImageAsset* getHighlightAsset();

		void newAssetImported(const std::string &a_fileName);
	};

} }