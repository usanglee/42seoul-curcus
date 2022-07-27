import { useSetRecoilState } from 'recoil';
import { modalState } from 'utils/recoil/modal';
import ChannelList from 'components/lobby/ChannelList';
import 'styles/Lobby/Lobby.css';

function Lobby() {
  const setModalInfo = useSetRecoilState(modalState);

  const openGameModal = () => {
    setModalInfo({ modalName: 'MAIN-START' });
  };

  return (
    <div className='lobby'>
      <div id='lobbyTitle'>Lobby</div>
      <button onClick={openGameModal} id='gameStart'>
        Game Start
      </button>
      <ChannelList />
    </div>
  );
}
export default Lobby;
