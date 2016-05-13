/*!
 * @brief	�O���t�B�b�N�X�R���t�B�O�B
 */

#ifndef _TKGRAPHICSCONFIG_H_
#define _TKGRAPHICSCONFIG_H_

namespace tkEngine{
	/*!
	 * @brief	�G�b�W���o�����̃R���t�B�O
	 */
	struct SEdgeRenderConfig{
		bool isEnable;		//!<�G�b�W���o�������L�����ǂ����̃t���O�B
		int	idMapWidth;		//!<ID�}�b�v�̕��B
		int idMapHeight;	//!<ID�}�b�v�̍����B
	};
	
	/*!
	 * @brief	�e�����̃R���t�B�O�B
	 */
	struct SShadowRenderConfig{
		bool 	isEnable;			//!<�e�𗎂Ƃ��������L�����ǂ����̃t���O�B
		int		shadowMapWidth;		//!<�V���h�E�}�b�v�̕��B
		int		shadowMapHeight;	//!<�V���h�E�}�b�v�̍����B
	};
	/*!
	* @brief	Bloom�̃R���t�B�O
	*/
	struct SBloomConfig {
		bool	isEnable;		//!<�u���[�����L�����ǂ����̃t���O�B
	};
	/*!
	 * @brief	�O���t�B�b�N�X�R���t�B�O�B
	 */
	struct SGraphicsConfig{
		SEdgeRenderConfig		edgeRenderConfig;		//!<�G�b�W���o�����̃R���t�B�O�B
		SShadowRenderConfig		shadowRenderConfig;		//!<�e�̏����̃R���t�B�O�B
		SBloomConfig			bloomConfig;			//!<Bloom�̃R���t�B�O�B
	};
}

#endif //_TKGRAPHICSCONFIG_H_